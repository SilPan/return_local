# return local

Example of C local variable stack allocation behaviour,
and how returning local variables can be undefined behaviour.

The function `foo()` creates a 128 element `long int` array, fills it with the numbers from `begin` to `end` and returns it.

Reading the first elements of `arr` directly after invoking `foo()` for the first time yields the expected results.

But when reading `arr` again after a subsequent call to `foo()` with other parameters, the contents of `arr` have changed.
*Even though `foo()` does not even know the variable `arr`.*

What happens is, that `foo()` allocates the space for it's local array `bar` on it's stack and then returns a pointer to `bar` to it's caller.
But after returning the space `foo()` used for `bar` is not owned by foo anymore and a subsequent function invocation (in our case `foo()` again) will use the same space for it's local variables.

---

Compile with `gcc -g -O0 -D_FORTIFY_SOURCE=0 -fno-stack-clash-protection  -fno-stack-protector -std=c99 -o return_local return_local.c`.

Run with `./return_local`:

---

## expected output

```
num: 256
num: 257
num: 258
num: 256
num: 257
num: 258
```

## actual output

```
num: 256
num: 257
num: 258
num: 128
num: 129
num: 130
```

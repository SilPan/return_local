#include <stdio.h>

/**
 * Function that creates a 128 element long int arry and fills it with the 128 values between begin and end.
 */
long** foo(int begin, int end);

int main(void){
    long** arr;
    arr = foo(256, 384);
    printf("num: %i\n", *(arr + 0));
    printf("num: %i\n", *(arr + 1));
    printf("num: %i\n", *(arr + 2));
    foo(128, 256);
    printf("num: %i\n", *(arr + 0));
    printf("num: %i\n", *(arr + 1));
    printf("num: %i\n", *(arr + 2));
    return 0;
}

long** foo(int begin, int end){
    long bar[128];
    for(int i = 0; i < end-begin; i++){
        bar[i] = begin+i;
    }
    long** faz = (long**) &bar;
    return faz;
}

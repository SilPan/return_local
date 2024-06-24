#include <stdio.h>

/**
 * Function that creates a 128 int arry and fills it with the 128 values between begin and end.
 */
int** foo(int begin, int end);

int main(void){
    int** arr;
    arr = foo(256, 384);
    printf("num: %i\n", *arr);
    foo(128, 256);
    printf("num: %i\n", *arr);
    return 0;
}

int** foo(int begin, int end){
    int arr[128];
    for(int i = 0; i < end-begin; i++){
        arr[i] = begin+i;
    }
    int** faz = (int**) &arr;
    return faz;
}

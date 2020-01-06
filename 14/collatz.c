#include<stdio.h>
#include"collatz.h"

size_t
collatz
    (size_t n)
{
    int i = 0;
    while(n > 1){
        if(n%2){
            n = 3*n + 1;
        }
        else{
            n /= 2;
        }
        ++i;
    }
    return i;
}




size_t
collatz_verbose
    (size_t n)
{
    int i = 0;
    printf("  %10zi\n", n);
    while(n > 1){
        if(n%2){
            n = 3*n + 1;
        }
        else{
            n /= 2;
        }
        ++i;
        printf("->%10zi\n", n);
    }
    return i;
}

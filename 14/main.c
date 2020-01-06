#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"collatz.h"

int
main(int argc, char** argv)
{
    size_t n = 100;
    if(argc >= 2){
        n = atoi(argv[1]);
    }
    if(argc == 3 && !strcmp(argv[2], "chain")){
        printf("the starting number %zi produces the following chain:\n");
        size_t length = collatz_verbose(n);
        printf("with the chain length %zi\n", length);
        exit(0);
    }


    size_t max = 0;
    size_t idx = 0;
    for(size_t i = n/2; i < n; ++i){
        size_t tmp = collatz(i);
        if(max < tmp){ 
            idx = i;
            max = tmp;
        }
    }
    printf("Starting number for longest chain: %zi\n", idx);
}

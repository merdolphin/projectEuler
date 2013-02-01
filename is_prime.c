// gcc -c is_prime.c
// ar rs libisprime.a is_prime.o
// gcc -c -fpic is_prime.c
// gc -shared -o libisprime.so is_prime.o

#include <stdio.h>
#include <math.h>


int is_prime(int N){
    int i;
    
    if(N == 2)
        return 1;
    
    if(N > 2){
        for(i=2; i<sqrt(N)+1; i++)
            if(N%i == 0){
                return 0;
            }
        return 1;
    }
    return 0;
}


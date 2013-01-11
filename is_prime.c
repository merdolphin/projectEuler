#include <stdio.h>
#include <math.h>

int is_prime(int N){
    int i;
    
    if(N == 2)
        return 1;

    for(i=2; i<sqrt(N)+1; i++)
        if(N%i == 0){
            return 0;
        }
     return 1;
}


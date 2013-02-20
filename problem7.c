// Problem 7
//written by lina <lina.oahz@gmail.com> on Wed Jan  9 23:17:33 SGT 2013

#include <stdio.h>
#include <math.h>

#define PRIME_MAX 6      

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

int main(){   
    
    int counter = 0;
    int j;

    for(j=2;j<200000;j++){
        if(is_prime(j))
            counter++;
        if(counter == 10001)
            break;
    }
    printf("%d\n", j);

    return 0;
}

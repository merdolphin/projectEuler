/* Problem 7
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

//written by lina <lina.oahz@gmail.com> on Wed Jan  9 23:17:33 SGT 2013
///////// compile////////////
//gcc -Wall -O3 -o 10001st_prime 10001st_prime.c -lm
/////////////////////////////

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

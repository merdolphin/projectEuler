/* problem50.c */

// written by lina <lina.oahz@gmail.com> 
// start: Tue Feb  5 17:36:11 SGT 2013
//   end: Wed Feb  6 03:16:50 SGT 2013

#include <stdio.h>
#include <libisprime.h>
#include <stdlib.h>

#define N 1000000

int main(){

    int i, j;
    int primes[N];
    //primes = malloc(N* sizeof(int));
    int index = 0;
    int longest = 0;

    for(i=1; i<=N; i++)
        if( is_prime(i) ) 
            primes[index++] = i;

    for(j=0; primes[j]; j++){
        int s = 0;
        int k;
        int count = 0;
        //printf("prime[%d] is %d\n", j, primes[j]);
        for(k=j; primes[k]; k++){
            s += primes[k];
            count++;
            if(is_prime(s) && s< N && count > longest){
                printf("sum is: %d count is: %d\n",s, count);
                longest = count;
            }
        }
    }
    //free(primes);                       
    return 0;
            
}

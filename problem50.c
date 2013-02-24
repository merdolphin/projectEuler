/* problem50.c */

// written by lina <lina.oahz@gmail.com> 
// start: Tue Feb  5 17:36:11 SGT 2013
//   end: Wed Feb  6 03:16:50 SGT 2013
// last modification on Sun Feb 24 14:46:26 SGT 2013

#include <stdio.h>
#include <libisprime.h>
#include <stdlib.h>

#define N 1000000

int main(){

    int i, j;
    int primes[N];
    int index = 0;
    int longest = 0;

    for(i=1; i<=N; i++)
        if( is_prime(i) ) 
            primes[index++] = i;

     int s;
     int k;
     int count = 0;
     int sum = 0;

    for(j=0; primes[j]; j++){
           count = longest;
           
           for(k=j+1;k<j+1+longest;k++)
               s += primes[k];
           
           if(s>N)
               break;
                
           for(k=j+1+longest; primes[k]; k++){
                s += primes[k];
                count++;
                
                if(s > N)
                    break;
                if(is_prime(s)){
                    longest = count;
                    sum = s;
                }
           }
    }
            
        
     printf("sum is: %d count is: %d\n",sum, count);
                     
    return 0;
            
}

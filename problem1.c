/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

// usage gcc -Wall -O3 -o problem1 problem1.c

// written by lina on Sun Jan  6 23:19:11 SGT 2013

#include <stdio.h>

int main(){
    
    int i, limit; 
    long sum;
    
    limit = 1000;    
    sum = 0;

    for (i=1; i < limit; i++) {
        
        if(i%3 == 0 || i%5 ==0){
            //printf("i is %d\n", i);
            sum += i;
        }

    }

    printf("sum is %ld\n", sum);
        
    return 0;
 }

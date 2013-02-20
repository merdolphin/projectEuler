/* Problem 5
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <stdio.h>

int main(){
 
    int i;
    long N=4882009;
    
    while(N){
        //printf("%ld\n", N);
        for(i = 2; i<=20; i++){
            if(N%i != 0)
                break;
        }
        if(i == 21){
            break;
        }else{
            N++;
        }
    }
    
    printf("The smallest one is %ld\n", N);
    
    return 0;
}

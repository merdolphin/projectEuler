/* Problem 7
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

#include <stdio.h>

int main(){
   
    int count = 1;
    long i;
    long n = 2;
    
    while(1){
        
        for(i=2; i<n; i++){
            if(n%i == 0){
                n = n+1;
                break;
            }
        }
        if(i == n){
            count += 1;
            printf("%ld is the %dth primer.\n", n, count);
            }
        if(count == 1001)
            break;
            }

    return 0;
}

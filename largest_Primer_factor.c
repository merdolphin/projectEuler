/*
What is the largest prime factor of the number 600851475143 ?
*/

#include <stdio.h>


long find_largest_prime_factor(long N){
    
    long largest_prime = 3;
    long i, j;
    
    for(i=2; i<N; i++){

        if(N%i == 0){
            /* check whether i is primer */
            for(j=3; j<i; j++){  
                 if(i%j == 0)
                     break;
            }     
            if(j==i){
                largest_prime = i;
                printf("prime is %ld\n", largest_prime);
                }
            
            
        }        
}
    return largest_prime;
}


int main(){

    printf("largest prime is %ld\n",find_largest_prime_factor(13195));//600851475143));

    return 0;
}

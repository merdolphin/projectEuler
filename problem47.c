/* problem47.c */

// written by lina <lina.oahz@gmail.com> 
// start: Tue Feb  5 00:12:38 SGT 2013
//   end: Tue Feb  5 00:26:55 SGT 2013
// gcc --static -Wall -O3 -I./include -L./lib -o problem47 problem47.c  -lisprime -lm


#include <stdio.h>
#include <libisprime.h>

int four_prime_factors(int N){
    int c = 0;
    int i;
    for(i=2;i<N;i++){
        if( N%i==0 && is_prime(i) )
            c++;
    }
    if(c == 4)
        return 1;

    return 0;
}

int main(){
    int i;
    
    for(i=600;i<=1000000;i++)
        if( four_prime_factors(i) && four_prime_factors(i+1) && four_prime_factors(i+2) && four_prime_factors(i+3) ){
            printf("%d\n",i);
            break;
        }

     
     return 0;   
}


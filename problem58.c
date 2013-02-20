/* problem58.c */

// written by lina <lina.oahz@gmail.com> 
// start: Wed Feb 20 14:53:15 SGT 2013
//   end: Wed Feb 20 15:08:27 SGT 2013
// gcc --static -I./include -L./lib -Wall -O3 -o problem58 problem58.c -lisprime -lm


#include <stdio.h>
#include <libisprime.h>
#include <math.h>

int main(){
    
    int i = 1;
    
    float ratio = 1;

    int count_prime = 0;

    while(ratio > 0.1)
    {
        i+=2;
        if( is_prime(i*i-i+1) )
            count_prime++;
        if( is_prime(i*i-2*i+2) )
            count_prime++;
        if( is_prime(i*i-3*i+3) )
            count_prime++;
       
       ratio = (float) count_prime/(2*i-1);   
              
    }

    printf("%d\n", i);

    return 0;
}



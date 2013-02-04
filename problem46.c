/* problem46.c */

// written by lina <lina.oahz@gmail.com> 
// start: Mon Feb  4 23:45:05 SGT 2013
//   end: Tue Feb  5 00:10:34 SGT 2013
// gcc --static -Wall -O3 -I./include -L./lib -o problem46 problem46.c -lisprime -lm

#include <stdio.h>
#include <libisprime.h>
#include <math.h>

#define N 100000

int main(){

    int i;

    for(i=2; i<N; i++)
        if(!is_prime(i) && i%2 != 0){
            int j;
            for(j=1; j<i; j++){
                if( is_prime( i-pow(j,2)*2 ) )
                    break;
            }
            if(j==i)
                printf("%d\n",i);
            
        }

    return 0;
}

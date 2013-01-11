// Problem 10

// written by lina on Fri Jan 11 13:17:06 SGT 2013
//gcc --static -Wall -O3 -I./include -L./lib -o problem10 problem10.c -lisprime -lm

#include <stdio.h>
#include <libisprime.h>

#define N 2000000

//Below parts has been extracted to a separate library as libisprime
/* 
int is_prime(int n){
    int i;

    if(n == 2)
        return 1;

    for(i=2;i<sqrt(n)+1;i++)
        if(n%i == 0){
            return 0;
        }
    return 1;

}
*/

int main(){
    
    int j;
    long sum = 0;

    for(j=2;j<N;j++)
        if(is_prime(j))
            sum += j;
    printf("%ld\n",sum);

    return 0;
}

/* problem12.c */

// written by lina <lina.oahz@gmail.com> 
// start: Fri Feb  1 15:09:06 SGT 2013
//   end: Fri Feb  1 15:19:32 SGT 2013

#include <stdio.h>

#define N 30000000

int divisors(int a){
    int i;
    int count = 0;
    for(i=1; i<=a; i++)
        if(a%i == 0)
            count++;

    return count;
}



int main(){
    
    int i;
    int sum = 0;
    //int c = 0;

    for(i=1; i<=N; i++){
        sum += i;
        if(divisors(sum) >= 500){
            printf("%d %d %d\n",i, sum, divisors(sum)); 
            break;
        }
    }

    return 0;
}





/* problem30.c */

// written by lina <lina.oahz@gmail.com> 
// start: Tue Jan 29 13:35:29 SGT 2013
//   end: Tue Jan 29 15:41:13 SGT 2013

#include <stdio.h>
#include <math.h>

#define M 5
#define N 140736215222504 
//#define N 10000
int main(){
    
    long i, a, Tsum = 0;
    
    for(i=2; i<=N; i++){
        int sum = 0;
        a = i;
        while(a>10){
            sum += pow(a%10, M);
            a = a/10;
        }
        if(a<10){
            sum += pow(a,M);
        }
        if(i == sum){
            printf("%ld %d\n", i, sum);
            Tsum += i;
        }
    }

        //printf("%ld\n",pow(9,5)*81);
        printf("%ld\n", Tsum);

        return 0;
}


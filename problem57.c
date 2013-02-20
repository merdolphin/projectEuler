/* problem57.c */

// written by lina <lina.oahz@gmail.com> 
// start: Wed Feb 20 21:05:52 SGT 2013
//   end:

#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main(){

    int i;
    unsigned long numerator[N];
    unsigned long denominator[N];
    

    numerator[0] = 3;
    numerator[1] = 7;
    denominator[0] = 2;
    denominator[1] = 5;

    for(i=2;i<N;i++){
        numerator[i] = 2*numerator[i-1] + numerator[i-2];
        denominator[i] = 2*denominator[i-1] + denominator[i-2];
        printf("%ul / %ul\n", numerator[i],denominator[i]);

    }
    return 0;
}



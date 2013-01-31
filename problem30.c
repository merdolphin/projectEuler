/* problem30.c */

// written by lina <lina.oahz@gmail.com> 
// start: Thu Jan 31 16:46:06 SGT 2013
//   end:

#include <stdio.h>
#include <math.h>

#define E 5

int main(){

    unsigned long i, j, sum = 0;
    char buf[10];

    for(i=2; i<=100000000; i++)
    {
        long s = 0;
        snprintf(buf, sizeof buf, "%lu", i);
        for(j=0; buf[j] != 0; j++){
            s += pow(buf[j]-'0', E);
            //printf("%lu %lu\n", i, s);
        }

        if(s == i){
            printf("%lu\n", i);
            sum += i;
        }
    }
    printf("%ld\n",sum);
    return 0;
}

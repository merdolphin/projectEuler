/* problem64.c */
/* http://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Continued_fraction_expansion */

// written by lina <lina.oahz@gmail.com> 
// start: Sun Feb 17 23:44:20 SGT 2013
//   end: Mon Feb 18 00:41:37 SGT 2013

/// be ware of the sqrt trap.
/// Baby deserves better.
/// You ask more because you give more. -- L. N.

#include <stdio.h>
#include <math.h>

#define N 10000

int main(){
    
    int s;
    int m = 0;
    int d = 1; 
    int result = 0;
  
    for(s=2; s<=N; s++){
        //printf("%d\n",(int)(sqrt(s))*(int)(sqrt(s)));
        if((int)(sqrt(s))*(int)(sqrt(s)) != s){
            
            int a = sqrt(s);
            int period = 0;
            printf("a is %d, s is %d\n",a,s);
            while(1){
                m = d*a - m;
                d = (s - m*m)/d;
                a = ((sqrt(s) + m)/d);
                period++;
                //printf("%d p is %d\n",a, period);
                if(a == 2*(int)(sqrt(s)))
                    break;
            }
            if(period%2 !=0)
                result++;
        }
    }

    printf("%d\n",result);

    return 0;
}



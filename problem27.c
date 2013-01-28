/* problem27.c */

// written by lina <lina.oahz@gmail.com> on Mon Jan 28 21:25:21 SGT 2013
//

#include <stdio.h>
#include <libisprime.h> // self-build library

int formula(int a, int b, int n){
    return n*n + a*n + b;
}

int main(){
    
    int n;
    int a, b;
    int max = 1;

    for(a=-999;a<=999;a++)
       for(b=-999;b<=999;b++){
           int s = 0;
           for(n=0; n<=1000; n++)
            {
                if(!isprime(formula(a,b,n)) ){
                    break;
                    }else{
                        s += 1;
                    }
                if(s > max){
                    max = s;
                    printf("%d %d %d\n",a,b,n);
                }
              }
       }

    return 0;
}


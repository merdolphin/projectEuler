//Problem 9

// written by lina on Fri Jan 11 12:29:07 SGT 2013
// 

#include <stdio.h>
#define N 1000

int main(){
    
    int a, b, c;
    
    for(a=1;a<N/3;a++)
        for(b=a+1;b<N;b++)
            for(c=b+1;c<N;c++)
                if((a+b+c) == N){
                    if(a*a + b*b == c*c)
                    printf("%d %d %d %d\n", a, b, c,a*b*c);
                }

    return 0;
}

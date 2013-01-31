/* problem34.c */

// written by lina <lina.oahz@gmail.com> 
// start: Thu Jan 31 14:21:22 SGT 2013
//   end:
// 

#include <stdio.h>
#include <stdlib.h>


#define N 100000000

long factorial(int M){
    int i;
    long sum = 1;

    if(M == 1)
        return M;

    for(i=2; i<=M; i++)
        sum *= i;

    return sum;      
}

int main(){

    int i, j;
    int sum = 0;

    char buf[16];

    for(i=3; i<=N; i++){
        
        //buf = malloc(16* sizeof(char));
        snprintf(buf, sizeof buf, "%d", i);
        long s = 0;
        
        for(j=0; buf[j]!=0; j++){
            s += factorial(buf[j]-'0');
            
        }
        //printf("%d %ld\n",i, s);

        //free(buf);
           
       if( s == i){
            printf("%d\n",i); 
            sum += i;
       }
    }

    printf("%d\n",sum);
    return 0;

}


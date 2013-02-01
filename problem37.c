/* problem37.c */
// 
// written by lina <lina.oahz@gmail.com> 
// start: Fri Feb  1 00:37:00 SGT 2013
//   end: Fri Feb  1 13:27:34 SGT 2013
// gcc --static -Wall -O3 -I./include -L./lib -o problem37 problem37.c -lisprime -lm


#include <stdio.h>
#include <libisprime.h>
#include <math.h>

#define N 1000000

int remains(int a){
    
    int temp = a, tmp = 0;
    int m = 1;
    while(temp>10){
        tmp += temp%10*m;
        temp = temp/10;
        m*=10;
        //printf("temp is:%d\n",temp);
        //printf("tmp is %d\n", tmp);
        if(!is_prime(temp) || !is_prime(tmp))
            return 0;
    }
    return 1;
}


int main(){
    
    int i;
    int count = 0;
    int sum = 0;
    for(i=10; i<=N; i++)
        if(is_prime(i)){
            if(remains(i)){
                printf("%d\n",i);
                sum += i;
                count++;
                if(count == 11){
                    printf("sum is %d\n", sum);
                    break;
                }
            }
        }
          
    printf("%d\n", count);             
        
    return 0;
}



// Problem 12
// written by lina <lina.oahz@gmail.com>
//

#include <stdio.h>

long divisors(int N){
    
    int i, counter = 0;
    for(i=1;i<=N;i++)
        if(N%i==0)
            counter++;
    return counter;
}

long triangle(int N){
    int i,sum=0;
    for(i=1;i<=N;i++)
        sum += N;
    return sum;
}


int main(){
    long i;
    for(i=100000;i<5000000;i++){
        if(divisors(triangle(i))<450)
            i+=2000;
        if(divisors(triangle(i))>=500){
            printf("%ld\n",triangle(i));
            break;
        }
        printf("%ld\n",i);
    }
    return 0;
}

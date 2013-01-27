/* problem21.c */

// written by lina <lina.oahz@gmail.com> on Sun Jan 27 12:42:19 SGT 2013
//

#include <stdio.h>

int divisor_sum(int N){
    
    int i;
    int sum = 0;
    
    for(i=1; i<N; i++){
        if(N%i==0)
            sum += i;
    }

    return sum;
}

int is_amicable(int a, int b){

    if(divisor_sum(a) == b && divisor_sum(b) == a && a != b)
        return 1;

    return 0;
}

int main(){

    int i;
    int amicableSum = 0;

    for(i=1; i<10000; i++){
    
    if(is_amicable(i,divisor_sum(i)))
        amicableSum += divisor_sum(i);
    }

    printf("%d\n",amicableSum);

}

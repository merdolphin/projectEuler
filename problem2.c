
#include <stdio.h>

long fibonacci(int N){

    long i, sum = 1; 
    long TotalEvenSum = 2;
    long a = 1, b = 2;

    if (N == 2)
        sum = 2;
        
    if(N > 3){    
        for(i=3; i<=N; i++){
            sum = a + b;
            printf("%ld\n",sum);
            if(sum%2 == 0){
                TotalEvenSum += sum;
            }
            a = b; 
            b = sum;
        }
    }

    return TotalEvenSum;
   }


int main(){

    printf("The sum of the even-valued terms are: %ld\n", fibonacci(90));
    return 0;
}

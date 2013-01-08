/* Problem 6
The sum of the squares of the first ten natural numbers is,
12 + 22 + ... + 102 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/
// written by lina <lina.oahz@gmail.com> on Mon Jan  7 18:07:06 SGT 2013


#include <stdio.h>

#define n 100

long sum_of_squares(int N){
    int i;
    long sumOfSquares = 0;
   
    for(i=1; i<=N; i++)
        sumOfSquares += i*i;
   
    return sumOfSquares;
}

long square_of_the_sum(int N){
    int j, sum = 0;
    long sumSquare = 0;
   
    for(j=1; j<=N; j++)
        sum += j;

    sumSquare = sum*sum;
    
    return sumSquare;
}

int main(){
    
    long differences;

    differences = square_of_the_sum(n) - sum_of_squares(n);

    printf("%ld\n", differences);

    return 0;
}

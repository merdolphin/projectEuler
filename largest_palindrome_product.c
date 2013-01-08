/*A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


int is_palindrome(long N){
    
    long reverse = 0, temp; 
    
    temp = N;

    while(temp != 0 ){
        reverse = reverse * 10;
        reverse = reverse + temp%10;
        temp = temp/10;
    }
    
    if (N == reverse)
        return 1;
    else
        return 0;
}

int main(){
    
    int i, j;
    long m, largest_m = 1; 
    
    for(i=999;i>=500;i--){
        for(j=999;j>=500;j--){
            m = i*j;
            if(is_palindrome(m) && m > largest_m){
                largest_m = m;
                break;
            }
            }

    }
    
    printf("%ld\n", largest_m);    
    
    return 0;

}

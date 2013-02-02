/* problem 14 -- method 1 */

// written by lina <lina.oahz@gmail.com> on Sun Jan 13 17:35:55 SGT 2013
// modified on Fri Feb  1 16:35:04 SGT 2013

#include <stdio.h>

int chain_length (int N){

    unsigned count = 1;
    while(N>1){
        N = N%2 == 0 ? N/2 : (3*N+1); 
        count++;
    }
    return count;
}

int main(){
    int i;
    int max = 0;
    int number = 0; 
    int a;
    for(i=1;i<=1000000;i++){
        a = chain_length(i);
        if(a>max){
            max=a;
            number=i;
        }
        printf("%d %d %d %d\n",max, number,a, i);

        }
    
    
    return 0;
    }    


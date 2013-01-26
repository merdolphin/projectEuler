/* problem 14 -- method 1 */

// written by lina <lina.oahz@gmail.com> on Sun Jan 13 17:35:55 SGT 2013

#include <stdio.h>

int chain_length (int N){

    unsigned int count = 1;
    while(N>1){
        N = N%2 == 0 ? N/2 : (3*N+1); 
        count++;
    }
    return count;
}

int main(){
    int i;
    int max = 1;
    int number = 1; 
    int a;
    for(i=3;i<=13;i++){
        a = chain_length(i);
        if(a>max){
            max=a;
            number=i;
        }
        printf("%d %d %d\n",max, number,i);

        }
    
    
    return 0;
    }    


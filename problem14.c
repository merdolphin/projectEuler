/* problem 14 -- method 1 */

// written by lina <lina.oahz@gmail.com> on Sun Jan 13 17:35:55 SGT 2013
// modified on Fri Feb  1 16:35:04 SGT 2013

#include <stdio.h>

int chain_length (long N){

    unsigned count = 1;
    while(N>1){
        N = N%2 == 0 ? N/2 : (3*N+1); 
        count++;
    }
    return count;

    if(N==1)
        return count+1;

}

int main(){
    int i;
    int max = 0;
    int number = 0; 
    
    for(i=3;i<=1000000;i++){
        if(chain_length(i) > max){
            max=chain_length(i);
            number=i;
        }
        
        }
    
    printf("%d %d\n",max, number);

    return 0;
    }    


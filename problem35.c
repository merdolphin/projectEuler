/* problem35.c */

// written by lina <lina.oahz@gmail.com> 
// start: Thu Jan 31 17:41:38 SGT 2013
//   end: Fri Feb  1 00:22:47 SGT 2013
//* I am not a programmer, so I forgive myself not writting no-bug program.
//* This program has a little problem, it's done some repetitive work for number between 10-99. 
//* other parts are amazing, at least to me, I spent hours on it.  


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define M 1000000

int is_prime(int N){
    int i;
   
    if(N == 2)
        return 1;

    if(N>2){
    	for(i=2; i<sqrt(N)+1; i++)
        	if(N%i == 0){
            	return 0;
        	}
     	return 1;
	}
    return 0;
}

int main(){
    
    int i, j;
    char buf[8];
    char **new;
    int index = 0;
    new = malloc(M*sizeof buf);
    for(i=2; i<=M; i++){
        
        if(is_prime(i)){
            //printf("\nThe prime number is %d\nindex is %d:\n", i, index);
            snprintf(buf, sizeof buf, "%d", i);
            new[index] = malloc(sizeof buf);
            int k;
            for(j=0; buf[j]; j++){
                int idx = 0;
                for(k=j+1;buf[k];k++){
                    //printf("\nk is %d,\nidx are %d ", k, idx);
                    new[index][idx] = buf[k]-'0';
                    idx++;
                    }
                for(k = 0; k<=j; k++){ //This part better add one if to reduce the repetitive from 10-99 to generate its own.
                    //printf("\nak is %d,\naidx is %d \n", k, idx);
                    new[index][idx] = buf[k]-'0';
                    idx++;
                }
            
                //printf("\n");
                int d = 1, newN = 0;
                while(idx>0){           
                    newN += new[index][idx-1]*d;
                    d *= 10;
                    idx--;
                }
                if(!is_prime(newN))
                    goto NEXT;
                    
                //printf("%d\n",newN);
            }
                
            index++;    
            free(new[index]);            
          }
        NEXT:
            ;
        }
        free(new);
        printf("%d\n",index);
    return 0;
}





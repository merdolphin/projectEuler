/* problem27.c */

// written by lina <lina.oahz@gmail.com> 
// start: Mon Jan 28 22:25:21 SGT 2013
//   end: Tue Jan 29 00:09:08 SGT 2013
// gcc -o problem27 problem27.c -lm


#include <stdio.h>
#include <math.h>

int is_prime(int N){
    int i;
    
    if(N<=0)
        return 0;

    if(N == 2 || N == 1)
        return 1;

    if(N>2){
    	for(i=2; i<sqrt(N)+1; i++)
        	if(N%i == 0){
            	return 0;
        	}
     	return 1;
	}
}



int formula(int a, int b, int n){
    return n*n + a*n + b;
}

int main(){
    
    
    int a, b;
    int max = 1;
    int s;
    

    for(a=-999; a<=999; a++){
       for(b=-999; b<=999; b++){
           s = 0;
           int n;
           for(n=0; n<10000; n++)
               if(!is_prime(formula(a,b,n))){
                   break;
                   }else{ 
                        s += 1;
		                //printf("%d %d %d %d\n",a,b,formula(a,b,n),s,n);
		            }
               if(s == n && s > max){
                        max = s;
                      printf("%d %d %d\n",a,b,n);
                }        
              }
       }
    
    return 0;
}




/* problem66.c */

// written by lina <lina.oahz@gmail.com> 
// start: Sat Feb 16 14:20:18 SGT 2013
//   end: Sat Feb 16 15:04:06 SGT 2013
// Last minor modification on Sat Feb 16 21:57:41 SGT 2013 to speed up.
// chocked at the D = 61

#include <stdio.h>
#include <math.h>

#define MAXD 1000
#define MAX 10000000

int func(int x, int y, int D){
    
    if( pow(x,2)-D*pow(y,2) ==1 )
        return 1;

    return 0;
}

int is_quadratic(int N){
    if(sqrt(N)*sqrt(N) == N)
        return 1;
    return 0;
}

int main(){
    
    int i, j, d=1;
    
    int largest_x = 1, Dx = 1;
    
    while(d<MAXD){
       d: d++;
        if(! is_quadratic(d)){
            for(i=1; i<=MAX; i++){
                if(pow(i,2) - d*pow(MAX,2) >10000)
                    break;
                for(j=1; j<=MAX; j++){

                    //printf("%f\n", pow(i,2)-d*pow(j,2));
                    if( pow(i,2)- d*pow(j,2) <= 0)
                        break;
                       
                    printf("d is %d i is %d j is %d\n", d, i, j);
                    if( func(i, j, d) ){
                        printf("%d %d %d\n", i, d, j);
                        if(i>largest_x){
                            largest_x = i; 
                            Dx = d;
                        }                  
                     goto d;   
                    }
                }
            }
        }
    }
            
            
   printf("%d %d\n", largest_x, Dx);         
                

    
    return 0;
}

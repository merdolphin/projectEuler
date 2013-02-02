/* problem44.c */

// written by lina <lina.oahz@gmail.com> 
// start: Sat Feb  2 21:14:52 SGT 2013
//   end:

#include <stdio.h>
#include <math.h>

#define M 10

int formula(int n){

    return n*(3*n-1)/2;
}

int is_pentagonal(int s){
    // int i;
    //while(formula(i) <= s){
    //    if(formula(i) == s)
    //        return 1;
     //   i++;
    //}
    unsigned delta = sqrt(1+24*s);
    if( (1+ delta)%6 == 0){
        printf("%d %d\n", s, (1+delta)/6);
        return 1;
    }
    return 0;
}

int main(){
    
    int j, k;
    
    for(j=1; j<M; j++){
        int sum = 0, differences = 0;
        for(k=j+1; k<M; k++){
            sum = formula(j) + formula(k);
            differences = formula(k) - formula(j);
            if(is_pentagonal(sum) && is_pentagonal(differences))
                printf("j is %d  k is %d\n",j,k);
        }
        
        //printf("%d\n", formula(i));
    }

    return 0;
}

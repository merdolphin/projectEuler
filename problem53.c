/* problem53.c */

// written by lina <lina.oahz@gmail.com> 
// start: Wed Feb 20 16:10:39 SGT 2013
//   end: Wed Feb 20 16:57:52 SGT 2013

#include <stdio.h>
#include <gmp.h>

#define N 100

int greater(int n, int r){
    
    unsigned i, j;
    mpz_t numerator; 
    mpz_t denominator;
    mpz_t combinator;

    mpz_init_set_ui(numerator,1);
    mpz_init_set_ui(denominator,1);
    mpz_init_set_ui(combinator,1);

    for(i=n; i>r; i--)
        mpz_mul_ui(numerator,numerator,i);
      
    if( mpz_cmp_ui(numerator,1000000) < 0)
        return 0;
    
    for(j=1; j<=n-r; j++)
        mpz_mul_ui(denominator,denominator,j);        
        
    mpz_cdiv_q(combinator,numerator,denominator);

    if( mpz_cmp_ui(combinator,1000000) > 0)
        return 1; 
           
    return 0;    
}       
       

int main(){
    
    int n, r;
    int count = 0;
    
    for(n=1; n<=N; n++)
       for(r=1; r<=n; r++)
           if( greater(n,r) )
                count++;
    printf("%d\n",count);    
    return 0;
}



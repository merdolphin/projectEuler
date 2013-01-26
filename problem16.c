/* Problem 16 */

/* written by lina on Sat Jan 26 12:39:51 SGT 2013*/
// gcc -o problem16 problem16.c -lgmp -lm

#include <stdio.h>
#include <math.h>
#include <gmp.h>

#define N 1000

int main(){

    mpz_t result, sum, r;
    
    mpz_init (r);
    mpz_init (result);
    mpz_init (sum);

    mpz_set_d (result, pow(2,N));
        
    gmp_printf ("%Zd\n", result);

    while(1){  
        mpz_mod_ui (r, result, 10); 
        gmp_printf("%Zd\n",r);
     
        mpz_add (sum, sum, r);
        mpz_tdiv_q_ui(result, result, 10);
              
        if(mpz_cmp_ui(result,10)<0){
            mpz_add (sum, sum, result);
            break;
        }

    } 

    gmp_printf("%Zd\n",sum);

    mpz_clear (sum);
    mpz_clear (result);

    return 0;
    
}

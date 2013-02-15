/* problem55.c */

// written by lina <lina.oahz@gmail.com> 
// start: Thu Feb  7 18:18:46 SGT 2013
//   end:

#include <stdio.h>
#include <gmp.h>
#include <math.h>

int is_palindromic(mpz_t n){
    
    //int *p;
    //p = n-'0';

    gmp_printf("%Zd\n", n);

    return 0;
}

int main(){

    mpz_t i;
    mpz_init_set_ui(i,300);
    
    is_palindromic(i);
    
    printf("%f\n",sqrt(5));
    mpz_clear(i);
    return 0;
}

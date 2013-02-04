/* problem48.c */

// written by lina <lina.oahz@gmail.com> 
// start: Tue Feb  5 00:30:12 SGT 2013
//   end: Tue Feb  5 00:46:02 SGT 2013

#include <stdio.h>
#include <gmp.h>

#define N 1000

int main(){
    
    int i;
    mpz_t s;
    mpz_init(s);
    
    for(i=1; i<=N; i++){
        mpz_t fac;
        mpz_init(fac);
        mpz_ui_pow_ui(fac, i, i);
        mpz_add(s, s, fac);
    }
    gmp_printf("%Zd\n", s);
   

    return 0;
}

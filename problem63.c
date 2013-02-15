/* problem63.c */

// written by lina <lina.oahz@gmail.com> 
// start: Tue Feb 12 23:50:42 SGT 2013
//   end: Thu Feb 14 13:28:35 SGT 2013

#include <stdio.h>
#include <gmp.h>

#define N 5000

int main(){
    
    int i; 
    int j;
    int sum = 0;

    
    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){

                mpz_t power;
                
                mpz_init (power);
                mpz_ui_pow_ui(power, i,j);
                //gmp_printf("%Zd ", power);
                int m = 1;
                while(mpz_cmp_ui(power, 10) > 0){
                    mpz_cdiv_q_ui(power, power, 10);
                    m++;
                    if(m>j)
                        break;
                }
                //printf("m is %d\n", m);
                if(m == j){
                    printf("%d  %d\n",i,j);
                    sum++;
                }
                mpz_clear(power);
        }
    
    }

    printf("Total is %d\n", sum);

    return 0;
}


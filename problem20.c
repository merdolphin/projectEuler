/* problem 20 */
// written by lina <lina.oahz@gmail.com> on Sun Jan 27 00:23:33 SGT 2013
// gcc -Wall -O3 -o problem20 problem20.c  -lgmp

#include <stdio.h>
#include <gmp.h>
#include <string.h>

int main(){

    unsigned int i, j;
    char *str;
    int sum = 0;

    mpz_t factorial;
    mpz_init(factorial);
    mpz_set_ui(factorial,1);
    
    for(i=2;i<=100;i++){
        mpz_mul_ui(factorial,factorial,i);
    }
    
    //gmp_printf("%Zd\n",factorial);

    str = mpz_get_str(NULL, 10, factorial);

    mpz_clear(factorial);
    
    for(j=0;j<strlen(str);j++)
        sum += str[j] - '0';

    printf("%s\n%d",str,sum);
    
    return 0;

}


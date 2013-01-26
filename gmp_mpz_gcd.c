// `gmp_mpz_gcd.c'
//
// last major modification 2010/07/26
// last minor modification 2013/01/25
//
// gcc -o gmp_mpz_gcd gmp_mpz_gcd.c -lgmp -lm
// ./gmp_mpz_gcd
// 

#include <stdio.h>
#include <gmp.h>

int main(int nargs, char *args[]) {
	mpz_t a;
	mpz_t b;
	mpz_t g;

	mpz_init(a);
	mpz_init(b);
	mpz_init(g);

	if (1 < nargs) {
		mpz_set_str(a,args[1],10);
		if (2 < nargs) {
			mpz_set_str(b,args[2],10);
			}
		}

	mpz_gcd(g,a,b);

	gmp_printf("gcd(%Zd,%Zd):\t%Zd\n",a,b,g);

	mpz_clear(g);
	mpz_clear(b);
	mpz_clear(a);

	return (0); }

//
// End of file `gmp_mpz_gcd.c'. 

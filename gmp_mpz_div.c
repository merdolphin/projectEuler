// `gmp_mpz_div.c'
//
// last major modification 2010/08/04
// last minor modification 2013/01/25
//
// gcc -o gmp_mpz_div gmp_mpz_div.c -lgmp -lm
// ./gmp_mpz_div
// 

#include <stdio.h>
#include <gmp.h>

int main(int nargs, char *args[]) {
	mpz_t n;
	mpz_t d;
	mpz_t q;
	mpz_t r;

	mpz_init(n);
	mpz_init(d);
	mpz_init(q);
	mpz_init(r);

	mpz_set_ui(n,7UL);
	mpz_set_ui(d,2UL);

	if (1 < nargs) {
		mpz_set_str(n,args[1],10);
		if (2 < nargs) {
			mpz_set_str(d,args[2],10);
			}
		}

	mpz_cdiv_qr(q,r,n,d);
	gmp_printf("cdiv(%+Zd,%+Zd):\t%+Zd\t%+Zd\n",n,d,q,r);

	mpz_fdiv_qr(q,r,n,d);
	gmp_printf("fdiv(%+Zd,%+Zd):\t%+Zd\t%+Zd\n",n,d,q,r);

	mpz_tdiv_qr(q,r,n,d);
	gmp_printf("tdiv(%+Zd,%+Zd):\t%+Zd\t%+Zd\n",n,d,q,r);

	mpz_clear(r);
	mpz_clear(q);
	mpz_clear(d);
	mpz_clear(n);

	return (0); }

//
// End of file `gmp_mpz_div.c'. 

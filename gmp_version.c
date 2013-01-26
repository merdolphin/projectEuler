// `gmp_version.c'
//
// last major modification 2002/12/31
// last minor modification 2004/12/31
//
// gcc -o gmp_version gmp_version.c -lgmp -lm
// ./gmp_version
// 

#include <stdio.h>
#include <gmp.h>

int main(void){

	printf("%s\n",gmp_version);

	return 0;
}

//
// End of file `gmp_version.c'. 

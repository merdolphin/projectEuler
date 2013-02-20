/* problem57.C */

// written by lina <lina.oahz@gmail.com> 
// start: Wed Feb 20 21:17:37 SGT 2013
//   end: Wed Feb 20 22:14:07 SGT 2013

#include <iostream>
#include <gmpxx.h>
#include <string>
#include <sstream>

using namespace std;

#define N 1000

int more_digits(mpz_t a, mpz_t b){
    
    stringstream ss1;
    stringstream ss2;
    
    ss1 << a;
    ss2 << b;
  
    if ( ss1.str().length() > ss2.str().length() )
        return 1;
 
    return 0;
}

int main(){

    int i;
    
    int count = 0;

    mpz_t numerator[N];
    mpz_t denominator[N];
                
    mpz_init_set_ui(numerator[0], 3);
    mpz_init_set_ui(numerator[1], 7);
    mpz_init_set_ui(denominator[0], 2);
    mpz_init_set_ui(denominator[1], 5);

    mpz_t temp;
    mpz_init(temp);
    
    for(i=2;i<N;i++){

        mpz_init(numerator[i]);
        mpz_mul_ui(temp, numerator[i-1],2);
        mpz_add(numerator[i],temp,numerator[i-2]);

        mpz_init(denominator[i]);
        mpz_mul_ui(temp, denominator[i-1],2);
        mpz_add(denominator[i],temp,denominator[i-2]);

        if( more_digits(numerator[i],denominator[i]) )
            count++;
       
    }
    
    cout << count << endl;
    return 0;
}



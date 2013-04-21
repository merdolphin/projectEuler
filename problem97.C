//===========================================
//  problem97.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Mon Apr 15 13:20:10 SGT 2013
//    end: Mon Apr 15 13:48:45 SGT 2013
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <gmpxx.h>

using namespace std;

//============================================
// main code area
//============================================

int main(){

    mpz_t temp;
    mpz_init(temp);
    
    mpz_ui_pow_ui(temp, 2, 7830457);
    mpz_mul_ui(temp, temp, 28433);
    mpz_add_ui(temp, temp, 1);

    cout << temp << endl;

    mpz_clear(temp);

    return 0;
}



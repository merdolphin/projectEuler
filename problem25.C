//===========================================
//  problem25.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Mon Feb 25 21:58:25 SGT 2013
//    end: Tue Feb 26 00:51:14 SGT 2013
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <gmpxx.h>
#include <sstream>
#include <new>

using namespace std;

//============================================
// main code area
//============================================

void fib(mpz_t fn, int n){
    
    int i;
     
    mpz_t f1;
    mpz_init(f1);
    mpz_set_ui(f1,1);

    mpz_t f2;
    mpz_init(f2);
    mpz_set_ui(f2,1);

    for(i=3;i <= n; i++){
        mpz_add(fn,f2,f1);
        mpz_set(f1,f2);
        mpz_set(f2,fn);
    }

    mpz_clear(f1);
    mpz_clear(f2);    
}



int main(){
    
    int i;
        
    mpz_t fn;
    mpz_init(fn);
    
    mpz_t powonethous;
    mpz_init(powonethous);
    mpz_ui_pow_ui(powonethous, 10, 999);

    
    while(1){
        fib(fn, i);   
        if(mpz_cmp(fn,powonethous) > 0)
            break;
        i++;
    }

    mpz_clear(powonethous);
    mpz_clear(fn);

    cout << i << endl;

    return 0;
}



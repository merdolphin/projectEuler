//===========================================
//  problem419_1.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Tue Mar 19 11:43:51 SGT 2013
//    end: Wed Mar 20 00:39:25 SGT 2013
//
//  Very time-consuming, please look for _2.C
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <list>
#include <gmpxx.h>

using namespace std;

//============================================
// main code area
//============================================

#define N 1e12

int main(){
    
    list<int> seq, newseq;

    seq.push_back(1);
    list<int>::iterator it;
    
    unsigned long i;

    for(i=1; i<N; i++){

        newseq.clear();
        
        list<int>::iterator itlast = seq.begin();
      
        int count = 0;
        for(it = seq.begin(); it != seq.end(); it++){
           
            if(*it == *itlast){
                count++;
            }
            if(*it != *itlast){
                newseq.push_back(count);
                newseq.push_back(*itlast);
                count = 1;
                itlast = it;
            }
        }

        if(count > 0 ){
            newseq.push_back(count);
            newseq.push_back(*itlast);
        }

        seq.assign(newseq.begin(), newseq.end());
        
        }
    
    mpz_t an, bn, cn;
    mpz_init(an);
    mpz_init(bn);
    mpz_init(cn);
        
    for(it = newseq.begin(); it != newseq.end(); it++){
        if(*it == 1)
            mpz_add_ui(an, an, 1);
        if(*it == 2)
            mpz_add_ui(bn, bn, 1);
        if(*it == 3)
            mpz_add_ui(cn, cn, 1);
        }
    mpz_t ran, rbn, rcn, temp;
    
    mpz_init(ran);
    mpz_init(rbn);
    mpz_init(rcn);
    mpz_init(temp);
    
    mpz_ui_pow_ui(temp, 2, 30);
    mpz_mod(ran, an, temp);
    mpz_mod(rbn, bn, temp);
    mpz_mod(rcn, cn, temp);    
    gmp_printf("%Zd %Zd %Zd %Zd %Zd %Zd\n", an, bn, cn, ran, rbn, rcn);

    mpz_clear(temp);
    mpz_clear(an);
    mpz_clear(bn);
    mpz_clear(cn);
    mpz_clear(ran);
    mpz_clear(rbn);
    mpz_clear(rcn);

    return 0;
}



//===========================================
//  problem65.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Sun Mar 10 19:55:00 SGT 2013
//    end: Sun Mar 10 21:19:48 SGT 2013
//  
//  Please refer the algorithm in:
//  http://en.wikipedia.org/wiki/Continued_fraction
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <vector>
#include <gmp.h>
#include <sstream>

using namespace std;

//============================================
// main code area
//============================================

int main(){

    vector<int> va;
    
    va.push_back(2);

    for(int i=1;i<100;i++)
        if( (i+1)%3 == 0 ){
            va.push_back(2*(i+1)/3);
        }else{ 
            va.push_back(1);
        }

    mpz_t h[100]; // numerator: h_n = a_n * h_{n-1} + h_{n-2}
    //mpz_t k[100]; // denominator: k_n = a_n * k_{n-1} + k_{n-2}

    mpz_init_set_ui(h[0],2);
    mpz_init_set_ui(h[1],3);

    //mpz_init_set_ui(k[0],1);
    //mpz_init_set_ui(k[1],1);

    for(int i=2; i<va.size();i++){
        mpz_init(h[i]);
        //mpz_init(k[i]);
        
        mpz_t temp1;
        //mpz_t temp2;
        mpz_init(temp1);
        //mpz_init(temp2);

        mpz_mul_ui(temp1, h[i-1], va[i]);
        mpz_add(h[i], temp1, h[i-2]);

        //mpz_mul_ui(temp2, k[i-1], va[i]);
        //mpz_add(k[i], temp2, k[i-2]);

        mpz_clear(temp1);
        //mpz_clear(temp2);

    }

        
    stringstream ss1;
    ss1 << h[99];
    int result = 0;

    for(int i=0; i<ss1.str().length();i++)
        result += ss1.str()[i] - 48;

    cout << result << endl;
    
    return 0;
}



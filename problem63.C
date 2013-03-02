//===========================================
//  problem63.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Sat Mar  2 14:46:56 SGT 2013
//    end: Sat Mar  2 15:12:47 SGT 2013
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <cmath>
#include <math.h>
#include <sstream>
#include <gmpxx.h>
using namespace std;

//============================================
// main code area
//============================================

#define N 1000

int main(){

    int i, j;
    int count = 0;
    for(i=1; i<N; i++)
        for(j=1; j<N; j++){
            mpz_t a;
            mpz_init(a);
            mpz_ui_pow_ui(a,i,j);

            stringstream ss1;
            ss1 << a ;

            if(ss1.str().length() == j){
                cout << i << " " << j << endl;
                cout << a << endl;
                count++;
                cout << "count is " << count << endl;
            }

        }


    return 0;
}



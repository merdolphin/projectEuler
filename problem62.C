//===========================================
//  problem62.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Thu Feb 28 22:03:27 SGT 2013
//    end: Sat Mar  2 01:04:31 SGT 2013
//
// The running is so low due to use the gmp. 
// I am stuck about how to find out the cube of the big number.
// but this one is working except time consuming.
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <sstream>
#include <vector>
#include <gmpxx.h>

using namespace std;

//============================================
// main code area
//============================================

#define N 10000

bool is_cube(long double n){
    //long double 
    
    int cuber = cbrtl(n);//double cbrt(double x); float cbrtf; long double cbrtl;
   
    if( cuber*cuber*cuber == n){
        //cout << n << " " << cuber << endl;
        return true;
    }
    return false;
}

int main(){
    
    int i;
    stringstream ss1;
    
    for(i=1000; i<N; i++){
        mpz_t a;
        mpz_init(a);
        mpz_ui_pow_ui(a,i,3);

        ss1  << a;
        
        vector<int> cube;
        
        for(unsigned j=0; j<ss1.str().length();j++){
            int temp = ss1.str()[j] - 48;
            cube.push_back(temp);
        }
        
        int count = 1;
        do{
            mpz_t temp;
            mpz_init(temp);

            mpz_t m;
            mpz_init(m);
            mpz_set_ui(m,1);
            
            // for the new order, generate the temp 
            for(int k=cube.size()-1; k>=0; k--){
                mpz_t temp1;
                mpz_init(temp1);
                mpz_mul_ui(temp1, m, cube[k]);
                mpz_add(temp, temp, temp1);
                mpz_mul_ui(m, m, 10);
                mpz_clear(temp1);
            }
            
           
            
            if(mpz_cmp(temp, a) < 0)
                break;

            mpz_t k;
            mpz_init(k);
            mpz_set_ui(k,i); 
            
            do {
                mpz_add_ui(k,k,1);
                mpz_t temp2;
                mpz_init(temp2);
                mpz_mul(temp2, k, k);
                mpz_mul(temp2, k,k);
                if(mpz_cmp(temp, temp2) == 0)
                    count++;
                if(mpz_cmp(temp,temp2) < 0)
                    break;
                mpz_clear(temp2);
            }while(1);
                   
                 
            mpz_clear(temp);
            mpz_clear(m);
        }while(next_permutation(cube.begin(), cube.end()));
            
            mpz_clear(a);
        
        if(count == 5){
            cout << i << endl;
            break; 
        }
        
    }

    return 0;
}



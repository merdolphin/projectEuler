//===========================================
//  problem70.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Sun Mar  3 23:53:50 SGT 2013
//    end:
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include "isprime.h"
#include <vector>

using namespace std;

//============================================
// main code area
//============================================

#define N 87110

vector<long> primes;


float phin(long n){
     
     float phi = n;
     
     for(unsigned j=0; j<primes.size(); j++){
         if(n%primes[j] == 0)
             phi *= (float)(1-1.0/primes[j]);
         while( n%primes[j] == 0 ) 
             n /= primes[j];
     }

     return phi;
}


int main(){

    long i;

    long Phi;

    for(i=87109; i<N; i++){
        if( is_prime(i) ){
            primes.push_back(i);
            Phi = i*(1-1.0/i);
        }else{
            Phi = phin(i);
        }
         cout << "i is " << i << " " << Phi << endl;
    }
 
        

    
        
    return 0;
}



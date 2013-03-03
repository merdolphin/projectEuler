//===========================================
//  problem69_2.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Sun Mar  3 13:27:18 SGT 2013
//    end: Sun Mar  3 23:21:21 SGT 2013
//
/////////////////////////////////////////////
//
//  $ time ./problem69_2
//  510510
//
//  real	0m6.457s
//  user	0m6.444s
//  sys 	0m0.004s
//
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include "isprime.h"
#include <vector>
using namespace std;

//============================================
// main code area
//============================================

#define N 1000000

float n_phin(vector<long> primes, long n){ //Based on the Euler's_totient_function

    vector<long>relatively_prime;
    float nphin = 1.0;

    for(int j=0; primes[j] && primes[j]<=n; j++){

        if(n%primes[j] == 0)
            relatively_prime.push_back(primes[j]);
        while(n%primes[j] == 0)
            n /= primes[j];
    }
    

    for(unsigned j=0; j<relatively_prime.size(); j++)                     
           nphin *= (float)1.0/(1-1.0/relatively_prime[j]);

    return nphin;
}

int main(){
    
    long i;
    vector<long> primes;

    for(i=2; i<=N/1000; i++)
        if( is_prime(i) )
            primes.push_back(i);
     
    float max = 2;
    long maxnid = 1;    

    for(i=1; i<=N; i++){

        if( is_prime(i) ){
            if( max < (float)1.0/(1-1.0/i) ){
                max = (float)1.0/(1-1.0/i);
                maxnid = i;
            }
            goto d;
        }
            
        if( n_phin(primes, i)> max ){
            max = n_phin(primes,i);
            maxnid = i;
        }            
        d:;
        }
     cout << maxnid << endl;   
                                       
    return 0;
}



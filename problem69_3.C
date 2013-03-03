//===========================================
//  problem69_3.C -- the third version for problem 69
// 
//  written by lina <lina.oahz@gmail.com> 
//  start: Mon Mar  4 00:07:44 SGT 2013
//    end: Mon Mar  4 00:52:40 SGT 2013
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

vector<long> primes;

float n_phin(long n){ 

    vector<long>relatively_prime;

    float nphin = 1.0;
    
    for(unsigned j=0; j<primes.size() && primes[j]<=n; j++){

        if( n%primes[j] == 0 )
            relatively_prime.push_back(primes[j]);
        while(n%primes[j] == 0)
            n /= primes[j];
    }
    

    for(unsigned j=0; j<relatively_prime.size(); j++)                     
           nphin *= 1.0/(1-1.0/relatively_prime[j]);

    return nphin;
}

int main(){
    
    long i;     
    float max = 0;
    long maxnid = 1;    

    for(i=2; i<=N/1000; i++)
        if( is_prime(i) )
            primes.push_back(i);

    for(i=2; i<=N; i++){
            
            if( is_prime(i) ){
                if( max < (1.0/(1-1.0/i)) ){
                    max = (1.0/(1-1.0/i));
                    maxnid = i;
                }
            }else{
                if( n_phin(i)> max ){
                    max = n_phin(i);
                    maxnid = i;
                }
            }
    }
               
    cout << maxnid << endl;   
                                       
    return 0;
}



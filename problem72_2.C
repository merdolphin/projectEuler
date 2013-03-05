//===========================================
//  problem72_2.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Mon Mar  4 22:19:09 SGT 2013
//    end: Tue Mar  5 00:17:47 SGT 2013
//  
//  Summarize the Totient function to get the reduced proper frations
//  Still time-sucking, please refer to problem72_3.C for better solution.
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <vector>
#include "isprime.h"

using namespace std;

//============================================
// main code area
//============================================

#define N 1e6

vector<long> primes;

float Phi(long );

int main(){

    long i;
    float phin;
    
    long total = 0;

    for(i=2; i<N; i++)
        if( is_prime(i) )
            primes.push_back(i);
 
    for(i=2; i<=N; i++){

        if( is_prime(i) ){

            phin = i-1;
            
            }else{
            phin = Phi(i);
        }
        total += phin;
    }
         
    cout << total << endl;                    

    return 0;
}

float Phi(long n){
    
    vector<long> relative_prime;
    long tempn = n;
    float phin = n;
    for(unsigned i=0; i<primes.size() && primes[i]<n; i++){
        if(tempn%primes[i] == 0)
            relative_prime.push_back(primes[i]);
        while(tempn%primes[i]==0)
            tempn /= primes[i];
    }
    
    for(int j=0; j<relative_prime.size(); j++)
         phin *= (1- 1./relative_prime[j]);

    return phin;     
}

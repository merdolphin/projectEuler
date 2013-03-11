//===========================================
//  problem77.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Mon Mar 11 21:26:39 SGT 2013
//    end: Mon Mar 11 21:50:57 SGT 2013
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

int count(int , int );

vector<int> primes;

int main(){
    
    int N = 10;
    
    primes.push_back(1);
    for(int i=2; i<=N; i++)
        if( is_prime(i) )
            primes.push_back(i);

    while(count(N, primes.size()-1) <= 5000){
        N++;
        if( is_prime(N) )
            primes.push_back(N);
    }

    cout << N << endl;
      
    return 0;
}

int count(int n, int m){
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(n>=1 && m<=0)
        return 0;    
    return count(n, m-1) + count(n-primes[m], m);
}




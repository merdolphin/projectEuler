//===========================================
//  problem87.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Fri Mar 22 16:07:04 SGT 2013
//    end: Sun Mar 24 17:51:43 SGT 2013
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <cmath>
#include <math.h>
#include "prime.h"
#include <vector>
#include <algorithm>

using namespace std;

//============================================
// main code area
//============================================

#define N 5e7

int main(){
    
    int i;

    vector<long> primes;

    for(i=2; i<= sqrt(N); i++)
        if( is_prime(i) )
            primes.push_back(i);

    unsigned i2, i3, i4;

    vector<long> counter;

    for(i2=0; i2<primes.size(); i2++){
        for(i3=0; i3<primes.size(); i3++){
            if(pow(primes[i3],3) > N)
                break;
            for(i4=0; i4<primes.size(); i4++){
                if(pow(primes[i4],4) > N)
                    break;
                long a = pow(primes[i2],2) + pow(primes[i3],3) + pow(primes[i4],4);
                if(a <= N)
                    counter.push_back(a);
            }
        }
    }

    sort(counter.begin(), counter.end());
    vector<long>::iterator it = unique(counter.begin(), counter.end());
    counter.resize(distance(counter.begin(), it));
    cout << counter.size() << endl;
    
    return 0;
} 



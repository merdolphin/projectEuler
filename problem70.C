//===========================================
//  problem70.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Sun Mar  3 23:53:50 SGT 2013
//    end: Mon Mar  4 14:07:57 SGT 2013
//
// Still not fast enough. took 3m59.398s
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

#define N 10000000

vector<long> primes;


long phin(long n){
     
     long phi = n;
     
     for(unsigned j=0; j<primes.size() && primes[j]<=n; j++)
        if(n%primes[j] == 0){
            phi = phi - phi/primes[j];          
            while( n%primes[j] == 0 ) 
                n /= primes[j];
        }
             
     return phi;
}

bool is_permute(long a, long b){
   
    stringstream ss1; 
    stringstream ss2;
    ss1 << a;
    ss2 << b;
    vector<int> tempa;
    vector<int> tempb;

    if( ss1.str().length() != ss2.str().length() )
        return false;
  
    for(unsigned i=0; i<ss1.str().length(); i++){
        tempa.push_back(ss1.str()[i]-48);
        tempb.push_back(ss2.str()[i]-48);
    }
    sort(tempa.begin(), tempa.end());
    sort(tempb.begin(), tempb.end());
    
    for(unsigned i=0; i<tempa.size(); i++){
        if(tempa[i] != tempb[i])
            return false;
    }
    return true;
}
    
/// A trival way to check whether two datas are mutable, unused in this code

int is_permutable(long a, long b){
    stringstream ss1;
    ss1 << a;

    vector<int> tempa;
    for(unsigned j=0; j<ss1.str().length(); j++)
        tempa.push_back(ss1.str()[j]-48);
   do{
        stringstream ss1temp;
        for(unsigned j=0; j<tempa.size(); j++)
            ss1temp << tempa[j];
        long temp;
            ss1temp >> temp; 
        if(temp == b)
            return 1;       
    }while(next_permutation(tempa.begin(), tempa.end()));
    
    return 0;
}
/////////////////////////////////////////////////////////////////////

int main(){

    long i;

    long Phi;

    float min = 10000;
    long minid = 1;

    for(i=1; i<(N/1000); i++)
        if( is_prime(i) )
            primes.push_back(i);
    
    for(i=87109; i< N; i++){
        if( is_prime(i) ){
            Phi = i-1;
        }else{
            Phi = phin(i);
        }

        float temp = (float) i*1.0/Phi;
        if(  is_permute(i, Phi) && temp < min){    
            min = temp;
            minid = i;
        }  
    }
         
    cout << minid << endl;
            
    return 0;
}



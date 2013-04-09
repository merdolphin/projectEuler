//===========================================
//  problem95.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Wed Apr  3 21:14:22 SGT 2013
//    end:
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>

using namespace std;

//============================================
// main code area
//============================================

#define N 5915


long divisors(long a, long chain, long formera){    
    
    long sum = 0;
    
    for(int j=1; j<a; j++)
        if(a % j == 0 ){
            sum += j;
            cout << j << " " ;
        }
        cout << sum << endl;

    if(sum == 1)
        return 0;
    
    if(sum == formera)
        return 1;     
    
    if(sum > 1e6)
        return 0;    

    if( sum == a)
        return chain;
    chain++;    
    return divisors(sum, chain, a);
}



int main(){

    long max = 2;
    long maxID = 2;

    long i;

    for(i=2; i<=N; i++){
        cout << i << endl;
        long a = divisors(i, 1, 1); 
        if(a > max){
            maxID = i;
            max = a;  
        }
    }
        
    cout << maxID <<  " " << max << endl;    

    return 0;
}


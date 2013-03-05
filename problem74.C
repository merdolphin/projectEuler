//===========================================
//  problem74.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Tue Mar  5 22:17:23 SGT 2013
//    end: Tue Mar  5 23:32:02 SGT 2013
//
//  time :real	0m47.073s
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//============================================
// main code area
//============================================

#define N 1e6

long factorial(int );

int chain_length(long );

int main(){
    
    int i;
    int count = 0;

    for(i=2; i<N; i++)
        if( chain_length(i) == 60)            
            count++;
        
    cout << count << endl;

    return 0;
}

long factorial(int n){

    long temp = 1;
    for(int i=2; i<=n; i++)
        temp *= i;

    return temp;
}


int chain_length(long n){
    
    vector<long> loopsElements;
    
    loopsElements.push_back(n);

    d:
    stringstream ss1;
    ss1 << n; 
    long temp = 0;

    for(unsigned i=0; i<ss1.str().length(); i++)
        temp += factorial(ss1.str()[i]-48);
           

    for(unsigned i=0; i<loopsElements.size(); i++)
        if(temp == loopsElements[i])
            return loopsElements.size();
        
    loopsElements.push_back(temp);
    n = temp;

    if(loopsElements.size()>60)
        return 61;
    goto d;
}

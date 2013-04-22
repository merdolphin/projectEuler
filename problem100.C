//===========================================
//  problem100.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Mon Apr 22 22:21:22 SGT 2013
//    end: Mon Apr 22 22:31:06 SGT 2013
//
//  Please refer to http://www.alpertron.com.ar/QUAD.HTM
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

#define N 1e12

int main(){

    long b = 85;
    long t = 85+35;
    
    //bn+1 = 3*bn + 2*tn - 2
    //tn+1 = 4*bn + 3*tn - 3
    while( t < N ){
        long bn, tn;
        bn = 3*b + 2*t - 2;
        tn = 4*b + 3*t - 3;
        b = bn;
        t = tn;
    }
    
    cout << b << " " << 3*b + 2*t - 2 << endl;

    return 0;
}



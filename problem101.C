//===========================================
//  problem101.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Mon Apr 22 22:39:00 SGT 2013
//    end:
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

//============================================
// main code area
//============================================

int f(int n){
    int un = 1;

    for(int i=1; i<=10; i++)
        un += pow(-1,i) * pow(n,i);

    return un;
}

int main(){

    int i;

    for(i=1; i<=4; i++){
        cout << f(i) << " ";
    }
    cout << endl;

    return 0;
}



//===========================================
//  problem24.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Tue Feb 26 11:02:20 SGT 2013
//    end: Tue Feb 26 11:08:44 SGT 2013
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <algorithm>

using namespace std;

//============================================
// main code area
//============================================

#define N 10

int main(){

    int digits[N];

    int i;

    for(i=0;i<N;i++)
        digits[i] = i;
    int count = 0;

    do{
        count++;
        if(count == 1000000){
            for(i=0;i<N;i++)
                cout << digits[i];
            cout << endl;
        }
    }while(next_permutation(digits,digits+N));

    return 0;
}



//===========================================
//  problem91.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Fri Mar 29 14:52:22 SGT 2013
//    end: Fri Mar 29 15:26:37 SGT 2013
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

#define N 50

bool is_right_angle(int x1, int y1, int x2, int y2){
    
    int a, b, c;

    a = pow(x1,2) + pow(y1,2); 
    b = pow(x2,2) + pow(y2,2);
    c = pow(x2-x1,2) + pow(y2-y1,2);
    
    if( a>0 && b > 0 && c > 0 && ( a+b == c || a+c == b || a == b+c ) )
        return true;

    return false;
}

int main(){

    int x1, y1, x2, y2;

    int count = 0;
    
    for(x1=0; x1<=N; x1++)
        for(y1=0; y1<=N; y1++)
            for(x2=0; x2<=N; x2++)
                for(y2=0; y2<=N; y2++)
                    if(  is_right_angle(x1, y1, x2, y2) )
                        count++;
                    
    cout << count/2 << endl;                 
    return 0;
}



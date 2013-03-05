//===========================================
//  problem75.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Tue Mar  5 23:34:17 SGT 2013
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

#define L 15e5

bool only_one_triangle(long );

int main(){
    
    long l=36;
    if(only_one_triangle(l))
        cout << l << endl;

    return 0;
}

bool only_one_triangle(long l){
    
    int m, n;
    int result = 0;

    for(m=1; m<l; m++){
        
        //if( result == 2 )
        //    break;

        for(n=1; n<m; n++){
            int a =0, b = 0, c = 0;
            a = 2*m*n;
            b = m*m - n*n;
            c = m*m + n*n;

            if(a+b+c == l){
                result++;
                cout <<m << " " << n << " " << a << " " << b << " " << c << endl;
            }
        }
    }

    if(result == 1)
        return true;

    return false;    
}


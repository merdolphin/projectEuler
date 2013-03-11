//===========================================
//  problem75_2.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Tue Mar  5 23:34:17 SGT 2013
//    end:
//
//  Please refer:
//  http://en.wikipedia.org/wiki/Pythagorean_triple
// 
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
using namespace std;

//============================================
// main code area
//============================================

#define L 120

bool is_coprime(long m, long n){
    for(int i=2; i<=n; i++)
        if(m%i == 0 && n%i == 0)
            return false;
    return true;        
}

int main(){

    long m, n;
    long a, b, c;

    long result = 0;
    
    for(n = 1; n < ( sqrt(1+2*L) - 1)/2; n++)
        for(m = n+1; m < sqrt(L/2); m++)
     //for(n = 1; n < L; n++)
       //  for(m=n+1; m< L; m++)
            // m and n are coprime and m − n is odd
            if(is_coprime(m, n) ) {
                a = m*m - n*n;
                b = m*n;
                c = m*m + n*n;

                if(a + b + c <= L ){
                    cout << a+b+c << " " << a << " " << b << " " << c << endl;
                    result++;
                }
            }
            cout << result << endl;

}

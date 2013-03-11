//===========================================
//  problem418.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Sun Mar 10 21:25:56 SGT 2013
//    end:
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;

//============================================
// main code area
//============================================


int main(){

    unsigned long n = 1;
      
    for(unsigned long i=1; i<=43; i++)
          n *= i;
    cout << n << endl;
    unsigned long a, b, c;

    unsigned long fn = 0;

    double temp = n;

    for(a=pow(n,1.0/3);a>=1; a--)
        if(n%a == 0){
            for(b=pow(n/a,1.0/2); b>=a; b--)
                                                              
                    if(n%(a*b) == 0) {
                        c = n/(a*b);
                        double temp1 = (double)c/a; 
                        //cout << temp1 << endl;
                        if(temp1 > temp)
                            break;
                       
                            temp = temp1;                
                            cout << a << " " << b << " " << c << endl;
                            fn = a+b+c;
                        
                    }
        }
                  
                
            cout << fn << " " << temp << endl;
      
        

    return 0;
}



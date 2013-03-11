//===========================================
//  problem75.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Wed Mar  6 16:00:48 SGT 2013
//    end:
//
//  A day without a smile is a day wasted.
//  And I waste three decades by far. 
//  -- lithium sodium
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

int main(){

    long a, b;
    
    long count = 0;

    for(long l=3; l<=L; l++){

        int result = 0;
        for(a=1; a<l/3;a++){
            for(b=a; b<=(l-a)/2;b++){

                if( a*a + b*b == (l-a-b)*(l-a-b) )
                    result++;
                                  
                }
            if( result >=2 )
                break;
        }
                                                 
        if(result == 1)            
            count++;
        
        
    }

    cout << count << endl;
    return 0;
}



//===========================================
//  problem94.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Sat Mar 30 23:07:45 SGT 2013
//    end: Sun Mar 31 14:33:46 SGT 2013
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

#define N 1e9

bool is_integral(long a, long b){
    
    long sq;

    if( b%2 != 0 )
        return false;

    if( a*a - (b/2)*(b/2) <= 0 )
        return false;

    sq = sqrt(a*a - (b/2)*(b/2));
    
    if( sq + b/2 < a ) {

        return false;
    }

    if(sq = 0 || sq*sq != a*a - (b/2)*(b/2) )
        return false;

    if( (b*sq) % 2== 0)
        return true;
            
    return false;
}

int main(){

    long a;
    long sum_perimeters = 0;

    for(a=2;a<N/3+1; a++){
        
        if( is_integral(a, a-1))
            if(3*a - 1 < N)
                sum_perimeters += 3*a - 1;                
        
        if( is_integral(a, a+1) )
            if(3*a + 1 < N)
                sum_perimeters += 3*a + 1;
    }

    cout << sum_perimeters << endl;
        
    return 0;
}



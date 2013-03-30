//===========================================
//  problem94.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Sat Mar 30 23:07:45 SGT 2013
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

#define N 1e9

bool is_integral(int a, int b){
    
   
    int sq;

    sq = sqrt(a*a - (b/2)*(b/2));

    if(sq*sq != a*a - (b/2)*(b/2) )
        return false;
    if( sq != 0 &&  (b/2*sq) % 2== 0)
        return true;
            
    return false;
}

int main(){

    int a;
    int sum_perimeters = 0;

    for(a=1;a<N/3; a+=2)
        if( is_integral(a, a+1) ){
          //  cout << a << endl;
            sum_perimeters += 3*a + 1;

    }

    cout << sum_perimeters << endl;
        
    return 0;
}



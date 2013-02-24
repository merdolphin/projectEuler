/* problem45.C */

// written by lina <lina.oahz@gmail.com> 
// start: Sun Feb 24 21:39:35 SGT 2013
//   end: Sun Feb 24 22:02:22 SGT 2013

#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int is_pentagonal(long p){

    if ( (long)sqrt(1+24*p) * (long) sqrt(1+24*p) == 1+ 24*p && (1+(long)sqrt(1+24*p))%6 == 0)
        return 1;
    return 0;
}
    

int main(){

    int i=144;
    
    while(1){
        if( is_pentagonal(i*(2*i-1)) )
            break;
        i ++;    
    }

    cout << i*(2*i-1) << endl;
    return 0;
}



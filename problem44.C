/* problem44.C */

// written by lina <lina.oahz@gmail.com> 
// start: Sun Feb 24 22:06:26 SGT 2013
//   end: Sun Feb 24 22:59:49 SGT 2013

#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

#define limit 100000000

int is_pentagonal(long p){
    long sq;
    sq = (long) sqrt(1+24*p);
    if(sq*sq == 1+24*p && (1+sq)%6 == 0)
        return 1;
    return 0;    
}

int main(){
    long j, k;
    long *pn;
    pn = new long[limit/5];
    int index = 0;

    int min = limit;

    for(j=1; j<=limit; j++)
        if( is_pentagonal(j) )
            pn[index++] = j;
    
    for(j=0; j<index-1; j++){
        for(k=j+1; k<index; k++){
             if( pn[k] - pn[j] > min)
                break;
             if( is_pentagonal(pn[j] + pn[k]) && is_pentagonal(pn[k]-pn[j]))
                min = min > pn[k]-pn[j] ? pn[k]-pn[j]: min;
        }
    }

    cout << min << endl;
    
    delete [] pn;
    return 0;
}



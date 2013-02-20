/* problem64.C */

// written by lina <lina.oahz@gmail.com>
// start: Mon Feb 18 00:43:09 SGT 2013
// end: Mon Feb 18 00:56:44 SGT 2013

#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

#define N 10000

int main(){

    int i;
    int result = 0;
    int m = 0;
    int d = 1;
    
    for(i=2; i<=N; i++){

        int a0 = sqrt(i);

        if(a0 * a0 != i){
            int period = 0;
            int a = a0;
            while(a != 2*a0){
                m = d*a -m;
                d = (i -m*m)/d;
                a = (a0 + m)/d;
                period++;
                //cout << a0 << endl;
            }
            if(period%2 == 1)
                result++;
        }
    }
    
    cout << result << endl;

    return 0;
}



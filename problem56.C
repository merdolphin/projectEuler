/* problem56.C */

// written by lina <lina.oahz@gmail.com> 
// start: Wed Feb 20 17:52:13 SGT 2013
//   end: Wed Feb 20 18:29:47 SGT 2013
// g++ -Wall -o problem56 problem56.C -lgmp -lgmpxx


#include <iostream>
#include <gmpxx.h>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

int digital_sum (mpz_t n){
    
    stringstream ss;
    int i;
    int sum = 0;
    
    ss << n;
    for(i=0; ss.str()[i];i++)
        sum += ss.str()[i]-48;
      
    return sum;
}

#define N 100

int main(){

    int a, b;
    
    int max = 1;

    mpz_t powab;
    mpz_init (powab);

    for(a=1; a<N; a++)
        for(b=1; b<N; b++){
            mpz_ui_pow_ui(powab, a, b);
            max = max < digital_sum(powab)? digital_sum(powab):max;
        }
        
    cout << max << endl;
    return 0;
}



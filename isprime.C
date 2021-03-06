/* isprime.C */

// written by lina <lina.oahz@gmail.com> 

#include <cmath>
#include <math.h>

template <typename T> 
int is_prime(T N){
    int i;        
    if(N == 2)
        return 1;
    
    if(N > 2){
        for(i=2; i<sqrt(N)+1; i++)
            if(N%i == 0)
                return 0;
        return 1;
    }
    return 0;
}



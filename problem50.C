/* problem50.C */

// written by lina <lina.oahz@gmail.com> 
// start: Sun Feb 24 13:26:29 SGT 2013
//   end: Sun Feb 24 14:33:09 SGT 2013

#include <iostream>
#include "prime.h"
#include <new>

using namespace std;

#define N 1000000

int main(){
    
    long i;

    long *primes;
    primes = new long[N/4];
    int index = 0;
    
    for(i=2; i<N; i++)
        if(is_prime(i))
            primes[index++] = i;
        
    
    int longest = 1;
    long s;
    int sum = 0;
    int j;
    int count = longest;

    for(i=0; primes[i];i++){
        
        s = 0;

        for(j=i+1; j<i+1+longest; j++)
            s += primes[j];
        
        if(s > N)
            break;
                
        while(primes[j]){
            s += primes[j];
            count++;
            j++;
            if(s>N)
                break;
            if(is_prime(s)){
                longest = count;
                sum = s;
            }
                
        }
            
    }
        
    
    
    cout << "longest is " << longest << " sum is " << sum << endl;    

    delete [] primes;
    return 0;
}



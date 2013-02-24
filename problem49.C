/* problem49.C */

// written by lina <lina.oahz@gmail.com> 
// start: Sun Feb 24 16:53:21 SGT 2013
//   end: Sun Feb 24 20:37:14 SGT 2013

#include <iostream>
#include <algorithm>
#include "prime.h"
#include <new>

using namespace std;

int mut(int n){
    int i;
    int data[4];
    int mdata[24];
    int index = 0;
    
    for(i=3;i>=0;i--){
        data[i] = n%10;
        n = n/10;
    }

    int temp;
    
    do {
        temp = data[0]*1000 + data[1]*100+data[2]*10+data[3];
        if(is_prime(temp))
            mdata[index++] = temp;                
        } while(next_permutation(data,data+4)); 

    for(i=1; i<index; i++)
        for(int j=index-1; j>i; j--)
            if(mdata[j]-mdata[i] == mdata[i] - mdata[0]){
               cout << mdata[0] << mdata[i] << mdata[j] << endl;
               return 1;
        }

    return 0;
}

int main(){
     
    int i;
    int *primes;
     
    primes = new int [1062];
    int index = 0;
     
    for(i=1000;i<10000;i++)
        if( is_prime(i) )
            primes[index++] = i;

    
    for(i=0;i<index/2;i++)
        mut(primes[i]);
        
    delete [] primes;
    return 0;
}



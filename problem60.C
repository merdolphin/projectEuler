/* problem60.C */

// written by lina <lina.oahz@gmail.com> 
// start: Thu Feb 21 01:14:43 SGT 2013
//   end: Fri Feb 22 01:44:04 SGT 2013
// last major modification on Fri Feb 22 13:49:58 SGT 2013
//* I used 6 ~ 8 hours to debug, later I decided to re-write whole things.
//* listen: if something sucks your time so long, just give up and re-do it.  
//* have the courage to let it go. 
//* think twice before doing once. be smart ... far better than ... be rash.
// g++ -Wall -o problem60 problem60.C prime.C

#include <iostream>
#include <sstream>
#include <string>
#include "prime.h"
#include <new>
 
#define limit 100000

using namespace std;

int catP(int *array, int a, int b){
    
    stringstream ss1, ss2;
    int val1 = 0, val2 = 0;
    ss1 << array[a] << array[b];

    ss1 >> val1;
    
    if(! is_prime(val1))
        return 0;
    
    ss2 << array[b] << array[a];
        
    ss2 >> val2;
    
    if(is_prime(val1) && is_prime(val2))
        return 1;
    
    return 0;     
}

int main(){

    int i;
    int index = 0;
    int minSum = 100000;
    
    int *primes = new int[limit];
    
   

    for(i=1; i<=limit; i++)
        if( is_prime(i) ){
   
            primes[index++] = i;
           
        }
    
    for(i=0;i<index/2;i++)

        for(int j=i+1; j<index; j++){
            if(primes[i] + 4*primes[j] > minSum)
                break;
            if(catP(primes,i,j)){
                for(int k=j+1; k<index; k++){
                    if(primes[i] + primes[j] + 3*primes[k] > minSum)
                        break;
                    if(catP(primes,i,k) && catP(primes,j,k)){
                        for(int m=k+1; m<index; m++){
                            if(primes[i] + primes[j] + primes[k] + 2*primes[m] > minSum)
                                break;
                            if(catP(primes,k,m) && catP(primes,i,m) && catP(primes,j,m)){
                                for(int n=m+1; n<index; n++){
                                    if(primes[i]+primes[j]+primes[k]+primes[m] + primes[n] > minSum)
                                        break;
                                    if(catP(primes,m,n) && catP(primes,k,n) && catP(primes,j,n) && catP(primes,i,n)){
                                        minSum = primes[i]+primes[j]+primes[k]+primes[m] + primes[n];
                                        cout << primes[i] << " " << primes[j] << " " << primes[k] << " " << primes[m] << " " << primes[n] << endl;
                                        }
                                }
                            }
                        }
                    }
                }
            }
        }
                                                                     
                       
        
                                   
                   
    cout << "Result is " << minSum << endl;
    delete [] primes;

    return 0;
}



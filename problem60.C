/* problem60.C */

// written by lina <lina.oahz@gmail.com> 
// start: Thu Feb 21 01:14:43 SGT 2013
//   end: Fri Feb 22 01:44:04 SGT 2013

#include <iostream>
#include <sstream>
#include <string>
#include "prime.h"
#include <new>
 
#define limit 100000

using namespace std;

int contancatePrime(int a, int b){
    stringstream ss1, ss2;
    ss1 << a << b;
    ss2 << b << a;
    
    int val1, val2;
    
    ss1 >> val1;
    ss2 >> val2;

    if(is_prime(val1) && is_prime(val2))
         return 1;

    return 0;     
    }

int main(){

    int i;
    int index = 0;
    int sum = 0;
    
    int *primes = new int[limit];
    
   

    for(i=1; i<=limit; i++)
        if( is_prime(i) ){
   
            primes[index++] = i;
           
        }

        int j, k, l, m;

    for(i=0; i<index/2;i++){
        for(j=i+1; j<index/2;j++)
            if(contancatePrime(primes[i],primes[j])){
                for(k=j+1; k<index; k++){
                    if( contancatePrime(primes[i],primes[k]) && contancatePrime(primes[j],primes[k]) ) {
                        for(l=k+1; l<index; l++){
                            cout <<  primes[i] << " " << " " << primes[j]<< " " << primes[k] << primes[l] << endl;
                            if( contancatePrime(primes[i],primes[l]) && contancatePrime(primes[j],primes[l]) ){
                              //  if(contancatePrime(primes[k],primes[l])){
                              //  cout <<  primes[i] << " " << " " << primes[j]<< " " << primes[k] << endl;
                               // for(int m=l+1; m<index; m++){
                                //     if( contancatePrime(primes[i],primes[m])  && contancatePrime(primes[j],primes[m]) && contancatePrime(primes[k],primes[m]) && contancatePrime(primes[l],primes[m])){   
                                        sum = primes[i]+primes[j]+primes[k] +primes[l];//+primes[m] ;
                                        cout << primes[i] << " " << " " << primes[j]<< " " << primes[k] <<  " " << primes[l] << " " << endl;
                                        goto d;
                                        break;
                                     }
                                     else{
                                         break;
                                         cout << "increase limits" << endl;
                                     }
                               
                                
                            }
                        }
                    }
                }
            }
                            
                                
                                                     
                d:cout << sum << endl;

    delete [] primes;

    return 0;
}



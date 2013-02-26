//===========================================
//  problem51.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Tue Feb 26 11:15:03 SGT 2013
//    end: Tue Feb 26 12:53:05 SGT 2013
//
//  g++ -Wall -o problem51 problem51.C prime.C
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <sstream>
#include <string>
#include "prime.h"
#include <new>

using namespace std;

//============================================
// main code area
//============================================

#define N 100000

int is_repeat(int n){
    
    unsigned i, j;
    
    int count;
    
    string digits[10];

    for(i=0;i<10;i++){
        stringstream ssk;
        ssk << i;
        digits[i] = ssk.str()[0];
    }
    
    stringstream ss1;
    ss1 << n;

    for(i=0;i<ss1.str().length()-1;i++)
        for(j=i+1;j<ss1.str().length();j++){

            if(ss1.str()[i] == ss1.str()[j]){
                count = 0;
                for(int k=0;k<10;k++){
                    
                    stringstream sstemp;
                    int temp;

                    sstemp <<  ss1.str().replace(i,1,digits[k]).replace(j,1,digits[k]);
                    sstemp >> temp;
                    
                    if( temp >N && is_prime(temp) )
                        count++; 
                }
            }
            
            if(count == 8)
                return 1;
 
            for(unsigned m=j+1; m<ss1.str().length();m++){
                if( ss1.str()[i] == ss1.str()[j] && ss1.str()[i] == ss1.str()[m] ){
                    count = 0;
                    for(int k=0;k<10;k++){
                    
                        stringstream sstemp;
                        int temp;

                        sstemp <<  ss1.str().replace(i,1,digits[k]).replace(j,1,digits[k]).replace(m,1,digits[k]);
                        sstemp >> temp;
                   
                        if( temp > N && is_prime(temp) )
                            count++;
                        
                    }
                }
            }
        if(count == 8)
            return 1;
        }                                   
            
    return 0;    
}


int main(){

    int i;

    int *primes;

    primes = new int [N];

    int index = 0;

    for(i=N; i<10*N; i++)
        if( is_prime(i) )
            primes[index++] = i;
            
    for(i=0;primes[i];i++){
        if( is_repeat(primes[i]) ){
            cout << primes[i] << endl;
            break;
        }
    }
    
    delete [] primes;
    
    return 0;
}



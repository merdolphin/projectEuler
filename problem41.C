/* problem41.C */

// written by lina <lina.oahz@gmail.com> 
// start: Mon Feb 25 00:27:52 SGT 2013
//   end: Mon Feb 25 00:57:12 SGT 2013
// g++ -Wall -o problem41 problem41.C 

#include <iostream>
#include <algorithm>
#include "prime.h"

using namespace std;

#define N 7

int main(){
    
    int i;
    int m;
    unsigned long temp;
    unsigned long largest = 1;

    int num[N];
        num[0] = N;
          
        
    for(i=0; i<N; i++)
        num[i] = i+1;

       
    do{
        m = 1;
        temp = 0;
        for(i=N-1; i>=0; i--){
            temp += num[i]*m;
            m *= 10;
        }

        if(temp < largest)
            break;

        if(is_prime(temp))
            largest = temp;
                        
    }while(next_permutation(num, num+N));

    cout << largest << endl;

    return 0;
}



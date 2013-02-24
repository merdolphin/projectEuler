/* problem43.C */

// written by lina <lina.oahz@gmail.com> 
// start: Sun Feb 24 23:07:11 SGT 2013
//   end: Mon Feb 25 00:21:04 SGT 2013

#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int i;
    int data[10];
    int temp;
  
    unsigned long sum = 0;
    int primes[7] = {2, 3, 5, 7, 11, 13, 17};
    int m;

    for(i=0; i<=9; i++)
        data[i]=i;

    do{
        for(i=1; i<=7; i++){
            temp = data[i]*100 + data[i+1]*10 + data[i+2];
            if(temp%primes[i-1] != 0)
                break;
        }
        if(i==8){

            m = 1;
           
            for(i=9;i>=0;i--){
                sum += (unsigned long) data[i]*m;
                m *= 10;
            }
        }
           
                      
    }while(next_permutation(data,data+10));

    cout << sum << endl;

    return 0;
}



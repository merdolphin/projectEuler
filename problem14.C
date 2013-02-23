/* problem14.C */

// written by lina <lina.oahz@gmail.com> 
// start: Sat Feb 23 15:28:15 SGT 2013
//   end: Sat Feb 23 16:20:21 SGT 2013

#include <iostream>
using namespace std;

int collatz(long n){
    
    int count = 1;
    
    while(n>1){
        n = n%2 == 0 ? (n/2):(3*n+1);
        count++;
    }
    return count;

    if(n==1)
        return count+1;
}

int main(){

    long longest = 1;
    int num = 1;
    
    for(int i=3;i<=1000000;i++)
        if(collatz(i) > longest){
            num = i;
            longest = collatz(i);
        }

    cout << longest << " " << num << endl;

    return 0;
}



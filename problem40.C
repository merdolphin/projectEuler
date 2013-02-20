/* problem40.C */

// written by lina <lina.oahz@gmail.com> 
// start: Wed Feb 20 13:01:16 SGT 2013
//   end: Wed Feb 20 13:42:11 SGT 2013

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define N 500000

int main(){

    int i;
    int result = 1;
    string decimalfraction;
    

    for(i=0;i<=N;i++){
        stringstream ss;
        ss << i;              
        decimalfraction += ss.str();
    }
    for(i=1; i<=N*2;i*=10)
        result *= decimalfraction[i]-48;
    cout << result << endl;    
    return 0;
}



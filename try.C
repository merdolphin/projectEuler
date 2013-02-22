#include <iostream>
#include <sstream>
#include <string>
#include "prime.h"
#include <new>
 

using namespace std;

int contancatePrime(int a, int b){
    stringstream ss1, ss2;
    ss1 << a << b;
    ss2 << b << a;
    
    int val1 = 0, val2 = 0;
    
    ss1 >> val1;
    ss2 >> val2;
    cout <<"val1 is " << val1 << "  " << val2 << endl;

    if(is_prime(val1) && is_prime(val2)){
        cout << "is yes." << endl;
         return 1;
    }

    return 0;     
    }

int main(){

    contancatePrime(109,7);

    return 0;
}

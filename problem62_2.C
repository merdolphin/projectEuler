//===========================================
//  problem62_2.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Sat Mar  2 12:59:49 SGT 2013
//    end: Sat Mar  2 14:14:12 SGT 2013
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

//============================================
// main code area
//============================================

bool is_cube(long n){

    int cuber = cbrtl(n);
    
    if( (long) cuber*cuber*cuber == n)
        return true;
            
    return false;
}
    

#define N 10000

int main(){

    int i;
    
    for(i=345; i< N; i++){
        long a = pow(i,3);

        stringstream ss1;
        ss1 << a;
        string s = ss1.str();

        int count = 0;
        do{
            long temp = 0;
            istringstream buffer(s);
            buffer >> temp;
            if(temp < a)
                break;        
            if(is_cube (temp) )
                count++;    
        }while(next_permutation(s.begin(), s.end()));
        
        if(count == 5){
            cout << a << endl;
            break;
        }
        
    }

    return 0;
}



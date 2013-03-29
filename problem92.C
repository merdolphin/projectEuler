//===========================================
//  problem92.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Fri Mar 29 15:29:49 SGT 2013
//    end: Fri Mar 29 17:15:39 SGT 2013
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <cmath>
#include <math.h>
#include <list>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

//============================================
// main code area
//============================================

#define N 1e7

//list<int> eightnine;
//int i;

int chain(int k){
  
    if(k == 1)
        return 0;
    if(k == 89)
        return 1;
    /*
    if( k < i){
        list<int>::iterator it;
        it = find(eightnine.begin(), eightnine.end(), k);
        if(it != eightnine.end()){
              return 1;    
        }else{
            return 0;
        }
    }
      */     
    stringstream ss1;
    ss1 << k;
    int temp = 0;
    for(int j=0; j<ss1.str().length(); j++)
        temp += pow(ss1.str()[j] - 48, 2);
        
    return chain(temp);
}

int main(){
    int count = 0;   
    int i; 
    for(i=2; i<N; i++)
        if( chain(i) )
            //eightnine.push_back(i);           
            count++;
        
   // cout << eightnine.size() << endl;
    cout << count << endl;

    return 0;
}



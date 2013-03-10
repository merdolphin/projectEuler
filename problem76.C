//===========================================
//  problem76.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Sun Mar 10 12:34:34 SGT 2013
//    end: Sun Mar 10 13:39:51 SGT 2013
//
//  For the algorithm please refer:
//  http://www.algorithmist.com/index.php/Coin_Change
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <vector>

using namespace std;

//============================================
// main code area
//============================================

vector<int> S;

int count(int n, int m){

    if(n==0)
        return 1;
    if(n<0)
        return 0;    
    if(n>=1 && m<=0)
        return 0;
    
    return  count(n, m-1) + count(n-S[m],m);
}

int main(){
    

    for(int i=0; i<=100; i++)
        S.push_back(i);

    cout << count(100,99) << endl;
            
    return 0;
}



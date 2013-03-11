//===========================================
//  problem78_1.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Mon Mar 11 22:05:46 SGT 2013
//    end: Mon Mar 11 22:50:17 SGT 2013
//
//  Please look for problem78_2.C which use
//  the Partition and generating function.
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

long count(int, int);

int main(){

    int N = 30;

    for(int i=0; i<=N; i++)
        S.push_back(i);
    
    while( count(N, S.size()-1) % (1000000) != 0 ){
        N++;
        S.push_back(N);
        cout << N << count(N,  S.size()-1) << endl;
    }

    cout << N << endl;
    return 0;
}

long count(int n, int m){
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(n>=1 && m<=0)
        return 0;
    
    return count(n, m-1) + count(n-S[m], m);
}

//===========================================
//  problem78_2.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Mon Mar 11 23:13:07 SGT 2013
//    end:
//
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


int gk(int m){

    return m*(3*m-1)/2;
}


int p(int n){
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
            
    int k=1;
    int pn = 0;
    int flag = 1;
    while( n-gk(k)>=0 ){
        pn += flag*( p(n-gk(k)) + p(n-gk(-k)) );
        k++;
        flag *= -1;
    }
    return pn;
}


int main(){

    int i;
    vector<int> vp;
    int N = 300;

    for(i=0; i<=N; i++){
        vp.push_back( p(i) );
        cout << p(i) << endl;
    }

    
    while(vp[N]%100 != 0){
        N++;
        //vp.push_back( p(N) );
       // cout << vp[N] << endl;
        
        int pN = 0;
        int k = 1;
        int flag = 1;
        while(N - gk(k) >= 0){
            pN += flag * ( vp[N-gk(k)] + vp[N-gk(-k)] );
            k++;
            flag *= -1;
        }
        vp.push_back(pN);
    }
    

    cout << "N is " << N << " " << p(N) << endl;


    //cout << p(4) << endl;

    return 0;
}



//===========================================
//  problem15.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Sun Apr  7 21:15:07 SGT 2013
//    end: Tue Apr  9 21:17:30 SGT 2013
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>

using namespace std;

//============================================
// main code area
//============================================

#define N 40

int main(){

    long lattice[N+1][N+1];

    lattice[0][0] = 1;
    lattice[1][0] = 1;
    lattice[1][1] = 1;

    for(int i=2; i<=N; i++){
        
        lattice[i][0] = 1;
        
        for(int j=1; j<=i-1; j++)
            lattice[i][j] = lattice[i-1][j-1]+lattice[i-1][j];

        lattice[i][i] = 1;
    }
   
   /*    
    for(int i=0; i<=N; i++){
        for(int j=0; j<=i; j++)     
            cout << lattice[i][j] << " "; 
            cout << endl;  
    }
    */
    cout << lattice[N][N/2] << endl;
    return 0;
}



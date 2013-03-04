//===========================================
//  problem71_2.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Mon Mar  4 16:33:21 SGT 2013
//    end: Mon Mar  4 20:58:59 SGT 2013
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

//============================================
// main code area
//============================================

#define N 1000000

int main(){

    long i, j;
    double min = 1.0;
    long min_j = 1;

    for(i=1; i<N; i++){
        for(j=floor( (3*i-1)/7-1 ); j<=(3*i-1)/7 + 1; j++){
            if(3*i == 7*j + 1){
                double temp;
                temp = (float) 3.0/7 - (float) j/ i ;

                if( temp <  min){
                    min = temp;
                    min_j = j;
                }
                break;
            }
        }
    }

    cout << min_j << endl;
           return 0;
}



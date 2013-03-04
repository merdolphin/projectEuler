//===========================================
//  problem71_1.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Mon Mar  4 15:35:30 SGT 2013
//    end: Mon Mar  4 20:38:23 SGT 2013
//
//  Another brute force one, very very time cousuming.
//  please look for the problem71_2.C for better solution.
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;

//============================================
// main code area
//============================================

#define N 1000000

int main(){

    int i, j;

    vector< vector<float> > sets;
    
    for(i=N; i>1; i--){
        for(j=floor(0.4443*i); j<i; j++){
            long tempi = i;
            long tempj = j;
            float temp = (float)j/i;
            
            if(temp > 0.44445)
                break;    

            vector<float> fractions;
            for(int k=2; k<=j; k++)
                if(tempi%k == 0 && tempj%k == 0){
                    tempi = tempi/k;
                    tempj = tempj/k;
                } 
                          
            temp = (float) tempj/tempi;
            
            fractions.push_back(temp);
            fractions.push_back(tempj);
            fractions.push_back(tempi);

            sets.push_back(fractions);

            cout << temp  << " " <<  tempj << "/" << tempi << endl;
        }
    }

    //vector<int>::iterator it;
   // it = unique(sets.begin(), sets.end());
   // sets.resize(distance(sets.begin(), it));
    
    sort(sets.begin(), sets.end());
    
    for(unsigned i=0; i< sets.size(); i++){
        if(sets[i][1] == 3 && sets[i][2] == 7)
            cout << sets[i-1][1] << endl; 
    }

    return 0;
}



//===========================================
//  problem73.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Tue Mar  5 14:55:31 SGT 2013
//    end: Tue Mar  5 15:47:45 SGT 2013
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//============================================
// main code area
//============================================

#define N 12000

int main(){

    long i, j;

    vector< vector<float> > set;

    for(i=2; i<=N; i++) // i indicate the denumerator
        for(j=1; j<i; j++){ // j indicate the numerator
            
            float temp = j*1.0/i;

            if(temp >= 1./3 && temp <= 1./2 ){
            
                long tempi = i;
                long tempj = j;
                for(int k=j; k>=2; k--)
                    if(tempi%k == 0 && tempj%k==0){
                        tempi /= k;
                        tempj /= k;
                    }
                vector<float> elements;
                elements.push_back(temp);
                elements.push_back(tempj);
                elements.push_back(tempi);
                set.push_back(elements);
            }
        }

    sort(set.begin(), set.end());

    std::vector< vector<float> >::iterator it;
    it = std::unique (set.begin(), set.end());
    set.resize( std::distance(set.begin(),it) );
           
    cout << set.size()-2 << endl;

    return 0;
}



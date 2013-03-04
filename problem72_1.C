//===========================================
//  problem72_1.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Mon Mar  4 21:00:18 SGT 2013
//    end: Mon Mar  4 21:38:02 SGT 2013
//
//  Another stupid brute-force. 
//  If "waiting" is really worthy?!
//  or if something is right doesn't need wait.
//
//  Please see problem72_2.C
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

#define N 1000000

int main(){

    long i, j;

    vector< vector<float> > set;

    for(i=2; i<=N; i++) // i indicate the denumerator
        for(j=1; j<i; j++){ // j indicate the numerator
            long tempi = i;
            long tempj = j;
            for(int k=j; k>=2; k--)
                if(tempi%k == 0 && tempj%k==0){
                    tempi /= k;
                    tempj /= k;
                }

            float temp = (float) j/i;
            vector<float> elements;
            elements.push_back(temp);
            elements.push_back(tempj);
            elements.push_back(tempi);
            set.push_back(elements);
        }

    sort(set.begin(), set.end());

    std::vector< vector<float> >::iterator it;
    it = std::unique (set.begin(), set.end());
    set.resize( std::distance(set.begin(),it) );
           
    cout << set.size() << endl;

    return 0;
}



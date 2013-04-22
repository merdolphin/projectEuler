//===========================================
//  problem99.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Mon Apr 22 20:54:41 SGT 2013
//    end: Mon Apr 22 21:20:11 SGT 2013
//
//  Programming brings me great comfort in my life.
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <math.h>
#include <vector>

using namespace std;

//============================================
// main code area
//============================================

int main(){

    ifstream myfile ("base_exp.txt");

    string line;

    float max = 3;
    int l = 1, maxline = 1;

    if( myfile.is_open() ){
        while( myfile.good() ){
            getline(myfile, line);
            
            istringstream split(line);
            vector<string> pair;
            
            for(string each; getline(split, each, ','); pair.push_back(each));

            stringstream ss1, ss2;

            ss1 << pair[0];
            ss2 << pair[1];

            float t1, t2, temp;
            ss1 >> t1;
            ss2 >> t2;

            temp = t2* log10(t1);
            
            if(temp > max){
                max = temp;
                maxline = l;
            }
            
            l++;
        }
    }

    cout << maxline << endl;

    return 0;
}



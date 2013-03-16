//===========================================
//  problem82.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Sat Mar 16 21:35:14 SGT 2013
//    end:
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

//============================================
// main code area
//============================================

int main(){

    ifstream matrixfile ("matrix.txt");
    
    string line;
    
    vector <vector <int> > matrix;

    if( matrixfile.is_open() ){
        while( matrixfile.good() ){
        
        getline(matrixfile, line);
        istringstream split(line);
        
        vector<int> cols;
        for(string each; getline(split, each, ','); ){
            
            stringstream ss1; 
            int temp; 
         
            ss1 << each; 
            ss1 >> temp; 
            cols.push_back(temp);
        }
        matrix.push_back(cols);
        }
    }
 
    
    int i; //j;

   // cout << matrix.size() << endl;
    
    for(i=0; i< 80; i++)
        matrix[i][78] += matrix[i][79];
    
        
   cout << matrix[79][78] << endl;
        
    return 0;
}




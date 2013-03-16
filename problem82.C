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
 
    
    int i, j;

    for(j=78; j>=0; j--)
        matrix[79][j] += matrix[79][j+1];
    
    for(i=78; i>=0; i--)
        for(j=78; j>=0; j--)
            matrix[i][j] += matrix[i+1][j] < matrix[i][j+1] ? matrix[i+1][j]:matrix[i][j+1];
        
   cout << matrix[0][0] << endl;
        
    return 0;
}




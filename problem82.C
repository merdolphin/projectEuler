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

   // cout << matrix.size() << endl;
    
    for(i=0; i< 80; i++)
        matrix[i][78] += matrix[i][79];
    
    /*
    for(j=77; j>=0; j--){
        matrix[0][j] += min( matrix[1][j], matrix[0][j+1]);
        
        for(i=1; i<=78; i++)
            matrix[i][j] += min( matrix[i-1][j], min( matrix[i+1][j], matrix[i][j+1]) );

        matrix[79][j] += min( matrix[79][j], matrix[79][j+1]);
    }
    */

    for(int k=0; k<79; k++)        
        cout << matrix[k][0] << endl;
    
    //cout << min(3, min(7, 2)) << endl;    
    return 0;
}

int min(int a, int b){
    return a<b ? a:b;
}


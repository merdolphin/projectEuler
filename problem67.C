//===========================================
//  problem67.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Sat Mar  2 16:47:07 SGT 2013
//    end: Sat Mar  2 20:59:47 SGT 2013
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

//============================================
// main code area
//============================================

#define N 101

int main(){

   
    ifstream myfile ("triangle.txt");
    
    vector< vector<int> > triangle;
    
    string line;

    int i = 0;

    if( myfile.is_open() ){

        while(myfile.good() ){

          getline(myfile, line);
          istringstream split(line);

          vector<string> tokens;
          for(string each; getline(split, each, ' '); tokens.push_back(each));        
          triangle.push_back( vector<int>() );  
          for(unsigned j=0; j<tokens.size();j++){
              stringstream sstemp;
              sstemp << tokens[j];
              int temp;
              sstemp >> temp;
              triangle[i].push_back(temp);
          }
          i++;
        }
    }
    
    for(int m = 98; m>=0 ;m--)
        for(int n = 0; n<=m; n++)
           triangle[m][n] += triangle[m+1][n] > triangle[m+1][n+1] ? triangle[m+1][n]:triangle[m+1][n+1];
    cout << triangle[0][0] << endl;
    
    return 0;
}



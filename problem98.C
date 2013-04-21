//===========================================
//  problem98.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Mon Apr 15 21:27:21 SGT 2013
//    end:
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <math.h>

using namespace std;

//============================================
// main code area
//============================================

bool stringsize (string a, string b){ return a.length() > b.length(); }

int main(){

    // Read file and extract all the words out.

    ifstream myfile ("words.txt");

    string line;
         
    vector<string> word;

    if ( myfile.is_open() ){
        while( myfile.good() ){
            getline(myfile, line);

            istringstream split(line);
                        
            for(string each; getline(split, each, ',');){
                each.erase(0,1);
                each.erase(each.end()-1);
                word.push_back(each);
            }
        }
    }
   

    // Look for the anagram word pairs

    vector<string> sorted_word;
    vector<string> pairs;

    sort(word.begin(), word.end(), stringsize);
    
    for(int i=0; i<word.size(); i++){
        sorted_word.push_back(word[i]);
        sort(sorted_word[i].begin(), sorted_word[i].end());
        for(int j=i-1;j>=0; j--)
            if(sorted_word[i] == sorted_word[j]){
                pairs.push_back(word[i]);
                pairs.push_back(word[j]);
            }
    }

    
    // identify the square anagram word

    for(int i=0; i<pairs.size(); i++)
        cout << pairs[i]<< endl;
    
    long square;
    
    int i = 0;
    int k = 1e5;

    while( i < pairs.size() ){
        
        map<char, int> dict;
            
        square = pow(k, 2);
        
        
        
        cout<< square << endl;
        
        i += 2;
    }


    return 0;
}



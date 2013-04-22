//===========================================
//  problem98.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Mon Apr 15 21:27:21 SGT 2013
//    end: Mon Apr 22 18:20:51 SGT 2013
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

    long result;

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

    long square;
    
    int i = 0;
    int k = sqrt(1e9) + 1;

    d:while( i < pairs.size() ){
            
        square = pow(k, 2);
        
        stringstream ss1;
        ss1 << square;

        if(ss1.str().length() > pairs[i].length()){
            k--;
        }

        if(ss1.str().length() == pairs[i].length()){
            map<char, int> dict;
            for(int m=0; m<pairs[i].length(); m++){
                for(map<char, int>::iterator it = dict.begin(); it != dict.end(); ++it){
                    if(it->second == (ss1.str()[m]-48) && it->first != pairs[i][m]){
                        k--;
                        dict.clear();
                        goto d;
                    }
                }
                dict.insert(std::pair<char, int>(pairs[i][m], ss1.str()[m]-48));
            }


            stringstream ss2;
            long temp;
            
            // kick off those with leading zeroes
            if( dict.find(pairs[i+1][0])->second == 0 ){
                k--;
                dict.clear();
                goto d;
            }
            
            for(int n=0; n<pairs[i+1].length(); n++)
                ss2 << dict.find(pairs[i+1][n])->second;

            ss2 >> temp;
            int tempa;
            tempa = sqrt(temp);
            
            // check whether is square and break if it is.
            if(tempa * tempa == temp){
                result = temp > square ? temp:square ;
                cout << result << endl;
                break;
            }else{
                k--;
            }

            dict.clear();   
        }
        
        if(ss1.str().length() < pairs[i].length()){
            i += 2;
            k = sqrt(k*k*10)+1;
        }

    }


    return 0;
}



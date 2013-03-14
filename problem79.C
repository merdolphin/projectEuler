//===========================================
//  problem79.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Tue Mar 12 21:52:22 SGT 2013
//    end: Thu Mar 14 12:01:58 SGT 2013
//
//  Hint: The passcode can be deciphered 
//  by eyes and pens in less than 2 mins.  
// 
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

//============================================
// main code area
//============================================

bool ordered(list<int> mylist, int key){
    
    list<int>::iterator it1, it2, it3;

    it1 = find(mylist.begin(), mylist.end(), key/100);
    it2 = find(mylist.begin(), mylist.end(), key/10%10);
    it3 = find(mylist.begin(), mylist.end(), key%10);
    
    int i1, i2, i3;

    i1 = distance(mylist.begin(), it1);
    i2 = distance(mylist.begin(), it2);
    i3 = distance(mylist.begin(), it3);
    
    if(i1<i2 && i2 < i3)
        return true; 
    
    return false;
}

int main(){
    

    ifstream keylogfile ("keylog.txt");

    string line;

    vector<int> keys;
    list<int> passcode;
    list<int>::iterator it;    

    if( keylogfile.is_open() )
        while( keylogfile.good() ){
            
            getline(keylogfile, line);
            if( !line.empty() ){
                
                stringstream ss1;
                ss1 << line;
                int temp;
                ss1 >> temp;
                keys.push_back(temp);
                sort(keys.begin(),keys.end());

                for(int i=0; i<3; i++){
                     for(it=passcode.begin();it!=passcode.end();it++)
                        if(line[i]-48 == *it)
                            break;
                    if( it == passcode.end() )
                        passcode.push_back(line[i]-48);        
                }
            }
        }


        do{         
            unsigned j;

            for(j=0; j<keys.size(); j++)

                if( ! ordered(passcode, keys[j]) )
                    break;

            if( j == keys.size() ){
                for(it=passcode.begin();it!=passcode.end();it++)
                    cout << *it;
                cout << endl;  
            }
        }while(next_permutation(passcode.begin(), passcode.end()) );
  
    return 0;
}



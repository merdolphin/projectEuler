//===========================================
//  problem419_2.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Wed Mar 20 00:44:15 SGT 2013
//    end:
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <list>

using namespace std;

//============================================
// main code area
//============================================

int main(){

    list<int> seq;

    seq.push_back(1);
    seq.push_back(1);
    seq.push_back(1);
    seq.push_back(2);
    seq.push_back(2);
    seq.push_back(1);
    //seq.push_back(1);
    //seq.push_back(1);


    

    
    list<int>::iterator it = seq.begin();
    list<int>::iterator itlast = seq.begin();
    int count = 1;

    for(advance(it,1); it != seq.end(); it++){
        if(*itlast == *it){
            count++;
            seq.erase(itlast);
        }else{
            seq.insert(itlast,count);
            itlast++;
            count = 1;
            }        
      cout << *itlast << " " << *it << endl;
    }
    
    if(count >= 1){
        it--;
        seq.insert(it,count);
    }
    
    for(it=seq.begin(); it != seq.end(); it++)
        cout << *it << " " ;
    cout << endl;
    
    return 0;
}



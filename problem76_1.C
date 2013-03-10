//===========================================
//  problem76_1.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Wed Mar  6 16:23:40 SGT 2013
//    end:
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <map>

using namespace std;

//============================================
// main code area
//============================================

int main(){

    map<int, int> mymap;
    for(int i=2; i<=100; i++)
            mymap[i] = 100/i;
   
    for(map<int, int>::const_iterator
        it = mymap.begin(); it != mymap.end(); ++it){
        cout << it->first << " " << it->second << endl;  
    }

    cout << mymap.size() << endl;
    return 0;
}



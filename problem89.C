//===========================================
//  problem89.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Mon Mar 25 18:12:20 SGT 2013
//    end:
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

//============================================
// main code area
//============================================

int main(){

    ifstream myfile ("roman.txt");
    string line;
    
    map<string, int> romans;
    map<string, int>::iterator it;

    romans["I"] = 1; 
    romans["V"] = 5;
    romans["X"] = 10;
    romans["L"] = 50;
    romans["C"] = 100;
    romans["D"] = 500;
    romans["M"] = 1000;

    cout << romans.size() << endl;


    if ( myfile.is_open() ){
        while( myfile.good() ){
            getline(myfile, line);

            int values = 0;
            
            for(int i=0; i<line.length(); i++){
                stringstream sstemp;
                sstemp << line[i];
                values += romans[sstemp.str()];
            }
     
            cout << values << endl;
            
            //cout << values << endl;
        }
    }

    return 0;
}



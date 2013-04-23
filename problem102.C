//===========================================
//  problem102.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Tue Apr 23 13:38:33 SGT 2013
//    end: Tue Apr 23 18:07:34 SGT 2013
//
//  please refer to 
//  http://en.wikipedia.org/wiki/Triangle#Using_coordinates
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

//============================================
// main code area
//============================================

float area(float x1, float y1, float x2, float y2, float x3, float y3){
    return 0.5*abs(x1*y2 - x1*y3 + x2*y3 -x2*y1 + x3*y1 - x3*y2);
}

int main(){
    
    int count = 0;

    ifstream myfile ("triangles.txt");
    string line;

    vector< vector<float> > coordinates;

    if( myfile.is_open() ){
        while( myfile.good() ){

            getline(myfile, line);
            istringstream split(line);
            
            vector<float> coordinate;
    
            for(string each; getline(split, each, ',');){ 
                
                    stringstream ss1;
                    ss1 << each;
                    float temp;
                    ss1 >> temp;
                    coordinate.push_back(temp);
            };
            coordinates.push_back(coordinate);
        }
    }

    /*
    for(unsigned int i=0; i<coordinates.size(); i++){
        for(unsigned int j=0; j<coordinates[i].size(); j++)
            cout << coordinates[i][j] << " ";
            cout << endl;
        }
    */

    for(unsigned int i=0; i<coordinates.size()-1; i++){
        if( area(coordinates[i][0], coordinates[i][1], coordinates[i][2], coordinates[i][3], 0, 0) + \
            area(coordinates[i][2],coordinates[i][3],coordinates[i][4],coordinates[i][5],0,0) + \
            area(coordinates[i][0],coordinates[i][1],coordinates[i][4],coordinates[i][5],0,0) == \
            area(coordinates[i][0],coordinates[i][1],coordinates[i][2],coordinates[i][3],coordinates[i][4],coordinates[i][5]) )
           
            count++;
    }

    cout << count << endl;

    return 0;

}




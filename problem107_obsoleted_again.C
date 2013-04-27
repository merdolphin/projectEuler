//===========================================
//  problem107.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Sat Apr 27 13:07:40 SGT 2013
//    end:
//
//  Please refer to:
//  http://en.wikipedia.org/wiki/Reverse-delete_algorithm
//    
//    1. Start with graph G, which contains a list of edges E.
//    2. Go through E in decreasing order of edge weights.
//    3. For each edge, check if deleting the edge will further disconnect the graph.
//    4. Perform any deletion that does not lead to additional disconnection.
//    
//
//============================================

//============================================
// Inculde
//============================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//============================================
// main code area
//============================================

struct edges_t {
    int edge;
    int v1; // vertice 1
    int v2; // vertice 2
};

bool myfunction (edges_t i, edges_t j) { return (i.edge > j.edge); }


int main(){

    long sum = 0, min = 0;

    // Read file and extract data into graph

    vector<edges_t> graph;
    
    ifstream myfile ("network.txt");
    string line;
    
    if( myfile.is_open() ){
        int i = 0, j;
        while( myfile.good() ){
            getline(myfile, line);
            istringstream split(line);  

            if( !line.empty() ){
                j = 0;    
                for(string each; getline(split, each, ','); j++){                    
                    if(each != "-" && j<=i){
                        edges_t temp;
                        stringstream(each) >> temp.edge;    
                        temp.v1 = i;
                        temp.v2 = j;
                        graph.push_back(temp);
                        sum += temp.edge;
                    }
                };
              i++;
            }
        }
    }


    sort(graph.begin(), graph.end(), myfunction);
    
    unsigned int i=0; 

   // cout << graph[466].edge << endl;
    
     while( i< graph.size() ){
        
        int countv1 = 0, countv2 = 0;
       
        for(unsigned int m=0; m<graph.size(); m++){

            if(graph[i].v1 == graph[m].v1 || graph[i].v1 == graph[m].v2)
                countv1++;
                
            if(graph[i].v2 == graph[m].v1 || graph[i].v2 == graph[m].v2)
                countv2++;

        }
        
        if( countv1>=2 && countv2>=2){
            graph.erase(graph.begin()+i);
        }else{
            i++;
        }
    }
                    
                     

    
    for(vector<edges_t>::iterator it=graph.begin(); it !=graph.end(); it++){
        cout << it->edge << " " << it->v1 << " " << it->v2 << endl;
        min += it->edge;
    }

    cout << sum << " " << sum - min << " " << min << endl;

    return 0;
}



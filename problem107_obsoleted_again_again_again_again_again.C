//===========================================
//  problem107.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Mon Apr 29 23:39:52 SGT 2013
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


bool connected(int ver1, int ver2, vector<edges_t> b){
        
    vector<int> possible_vs;
        
    for(unsigned int i=0; i<b.size(); i++){
        if( b[i].v1 == ver1){
            if(b[i].v2 == ver2){
                return true;
            }else{
                possible_vs.push_back(b[i].v2);    
            }
        }
    }

    for(unsigned j=0; j<possible_vs.size(); j++)
        if( connected(possible_vs[j], ver2, b) ){
            return true;
        }
                               
    return false;                    
}

int main(){

    long sum = 0, min = 0;

    vector<edges_t> graph;

    // Read file and extract data into graph
    
    //ifstream myfile ("network.txt");
    ifstream myfile("example.txt");
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
    
    //for(vector<edges_t>::iterator it=graph.begin(); it !=graph.end(); it++){
    //    cout << it->edge << " " << it->v1 << " " << it->v2 << endl;
    //}


    unsigned int i = 0;
    
    while( i < graph.size() ){
        edges_t temp;
        temp = graph[i];
        graph.erase( graph.begin()+i );
        cout <<"erase " << temp.edge << " " << temp.v1 << " " << temp.v2 << endl;
        if( ! connected(temp.v1, temp.v2, graph) ){
            cout << "add back again" << endl;
            graph.insert(graph.begin()+i, temp);   
            i++;  
        }    
    }
    
    for(vector<edges_t>::iterator it=graph.begin(); it !=graph.end(); it++){
        cout << it->edge << " " << it->v1 << " " << it->v2 << endl;
        min += it->edge;
    }
    
    long temp = sum - 259679;
    cout << sum << " I remove " << sum - min << " remain " << min  << " , other remove " <<  temp  << ", need remove extra " << temp-min << endl;
    
    return 0;
}



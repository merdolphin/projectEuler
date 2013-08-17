//===========================================
//  problem107.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Tue Apr 30 22:44:39 SGT 2013
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

bool found(int vanother, vector<edges_t> a){
    
    for(unsigned int i=0; i<a.size(); i++){
        if( a[i].v1 == vanother )
            for(unsigned int j=0; j<a.size(); j++)
                if( (j != i) && (a[i].v2 == a[j].v1 || a[i].v2 == a[j].v2) )
                    return true;
        if( a[i].v2 == vanother )
            for(unsigned int k=0; k<a.size(); k++)
                if( (k != i) && (a[i].v2 == a[k].v1 || a[i].v2 == a[k].v2) )
                    return true;       
    }
   

    return false;        
}


bool connected(int ver1, int ver2, vector<edges_t> b){
   
    if( found(ver1, b) )
        if( found(ver2, b) )
            return true;     
                        
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



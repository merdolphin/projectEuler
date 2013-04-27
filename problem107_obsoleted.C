//===========================================
//  problem107.C 
//
//  written by lina <lina.oahz@gmail.com> 
//  start: Tue Apr 23 22:45:28 SGT 2013
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
//#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>


using namespace std;

//============================================
// main code area
//============================================


bool myfunction (int i,int j) { return (i>j); }

int main(){

    long sum = 0, min = 0;

    ifstream myfile ("network.txt");
    
    string line;
    vector<vector<int> > matrix;

    if( myfile.is_open() ){
        while( myfile.good() ){
            
            getline(myfile, line);
            istringstream split(line);

            vector<int> edge;

            if( !line.empty() ){

                for(string each; getline(split, each, ',');){
                    stringstream ss1;
                    if(each == "-"){
                        edge.push_back(0);
                    }else{
                        ss1 << each;
                        int temp;
                        ss1 >> temp;
                        sum += temp;
                        edge.push_back(temp);
                    }
                };
                matrix.push_back(edge);
            }
        }
    }

    map<int, string>edges_s;
    map<vector<int>, string> ij_s; 
    
    for(unsigned int i=0; i<matrix.size(); i++)
        for(unsigned int j=0; j<i; j++)
            if( matrix[i][j] != 0 ){
                sum += matrix[i][j];
                
                vector<int> ij;
                ij.push_back(i);
                ij.push_back(j);
                
                stringstream sstemp;
                sstemp << i*100 + j;
                
                ij_s.insert( map<vector<int>, string>::value_type(ij, sstemp.str()) );
                edges_s.insert( map<int, string>::value_type(matrix[i][j], sstemp.str()) );
                ij.clear();
            }
    
    //sort(edges_s.begin(), edges_s.end(), myfunction);
    
    /* the following is obsolted

    for(map<int, string>::reverse_iterator rit = edges_s.rbegin(); rit != edges_s.rend(); rit++){
        cout << rit->first << " " << rit->second  << endl;
        for(map<vector<int>, string>::iterator it2 = ij_s.begin(); it2 != ij_s.end(); it2++){
            if(it2->second == rit->second){
                for(map<vector<int>, string>::iterator it3 = ij_s.begin(); it3 != ij_s.end() && it3 != it2; it3++)
                    if( it2->first[0] == it3->first[0] ){
                        for(map<vector<int>, string>::iterator it4 = ij_s.begin(); it4 != ij_s.end() && it4 != it2; it4++){
                            if( it2->first[1] == it4->first[1] ){
                                cout << rit->first << endl;
                                //ij_s.erase(it2);
                                cout << it2->first[0] << endl;
                            }
                        }
                    }
            }
        }
    }
 */


 
 /* The wrong way of doing it.         
    for(unsigned int j=0; j<matrix.size(); j++){
        int temp = 1000;
        for(unsigned int i=0;i<j+1;i++){
            sum += matrix[i][j];
            if(matrix[i][j] != 0 && matrix[i][j] < temp)
                temp = matrix[i][j];
        }
        min += temp;
        //cout << temp << " ";
        }
        cout << sum -min << endl;
    */

    /* The following one not working again. 

    unordered_multimap<int, vector<int> > edges;
    vector<int> graph;
    vector<int> vvertices;
    for(unsigned int i=0; i<matrix.size(); i++)
        for(unsigned int j=0; j<=matrix[i].size(); j++){
            if(matrix[i][j] != 0 ){
                vector<int>vertices;
                vertices.push_back(i);
                vertices.push_back(j);
                edges.insert(unordered_multimap<int, vector<int>>::value_type(matrix[i][j], vertices));
                graph.push_back(matrix[i][j]);
                vertices.clear();
           }
        }
   

    sort(graph.begin(), graph.end(), myfunction);

    for(vector<int>::iterator i = graph.begin(); i != graph.end(); i++){
        for(unordered_multimap<int, vector<int> >::iterator it = edges.begin(); it != edges.end(); ++it){
            if(*i == it->first){
                vvertices.push_back(it->second[0]);
                vvertices.push_back(it->second[1]);
            }
        }
    }

    for(vector<int>::iterator i = graph.begin(); i != graph.end(); i++){
        for(unordered_multimap<int, vector<int> >::iterator it = edges.begin(); it != edges.end(); ++it){
            if(*i == it->first){
                if( count(vvertices.begin(), vvertices.end(), it->second[0]) >1 &&  count(vvertices.begin(), vvertices.end(), it->second[1]) >1 ){
                    graph.erase(i);
                    cout << *i << " ;" << endl;
                    i--;
                    vector<int>::iterator ti = find(vvertices.begin(), vvertices.end(),it->second[0]);
                    vvertices.erase(ti);
                    vvertices.erase(ti);
                }
            }
        }
                
    } 
    
    for(vector<int>::iterator i = graph.begin(); i != graph.end(); i++){
        cout << *i << endl;
    }

    cout << sum << " " << min << endl;  
    */

    return 0;
}



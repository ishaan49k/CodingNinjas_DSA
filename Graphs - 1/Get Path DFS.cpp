// Final code
#include<iostream>
using namespace std;
#include<vector>

vector<int>* getPathHelper(int** edges, int n, int sv, int ev, bool* visited){
    if(sv == ev){
        vector<int>* output = new vector<int>();
        output->push_back(ev);
        return output;
    }

    visited[sv] = true;

    for(int i=0; i<n; i++){
        if(edges[sv][i] == 1 && visited[i] == false){
            vector<int>* smallPath = getPathHelper(edges, n, i, ev, visited);

            if(smallPath != NULL){
                smallPath->push_back(sv);
                return smallPath;   
            }
        }
    }
    
    return NULL;
    
}



vector<int>* getPath(int** edges, int n, int sv, int ev){
    // create visited array
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
    vector<int>* output = getPathHelper(edges, n, sv, ev, visited);
    
    delete [] visited;
    
    return output;
}

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
    // if sv != ev, we first mark sv as visited
    visited[sv] = true;
    
    // check if adj vertices of sv have a path to ev
    for(int i=0; i<n; i++){
        if(edges[sv][i] == 1 && visited[i] == false){ // call recursion on vertice which has edge with sv and is not visited
            vector<int>* smallPath = getPathHelper(edges, n, i, ev, visited);
            
            // in above recursion, if we get a path:
            if(smallPath != NULL){
                smallPath->push_back(sv);
                return smallPath;   // we now have 1 path from sv to ev. so we dont have to look for any other paths so just return this path
            }
        }
    }
    
    // for loop over means sv!=ev and we dint get path from any of sv's adj vertices
    // here we return NULL cuz it means there is no path from sv to ev
    return NULL;
    
}



vector<int>* getPath(int** edges, int n, int sv, int ev){
    // create visited array
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
    vector<int>* output = getPathHelper(edges, n, sv, ev, visited);
    
    // dynammic arrays are deleted by the functions that make them
    delete [] visited;
    
    return output;
}

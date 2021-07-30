#include <iostream>
#include <climits>
using namespace std;


int findMinVertex(int* weight, bool* visited, int n){
    
    int minVertex = -1; 
    
    for(int i=0; i<n; i++){

        if(visited[i] == false && (minVertex == -1 || weight[i] < weight[minVertex])){
            minVertex = i;
        }
    }
    
    return minVertex;
}







void prims(int** edges, int n){
    int* parent = new int[n]; 
    int* weight = new int[n];   
    bool* visited = new bool[n];
    

    for(int i=0; i<n; i++){
        visited[i] = false;
        weight[i] = INT_MAX;
    }

    parent[0] = -1;
    weight[0] = 0;
    

    for(int i=0; i<n; i++){
        int minVertex = findMinVertex(weight, visited, n);
        visited[minVertex] = true;
        
        for(int j=0; j<n; j++){
            if(edge[minVertex][j] != 0 && visited[j] == false){
                if(edge[minVertex][j] < weight[j]){
                    weight[j] = edge[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    for(int i=1; i<v; i++){
        if(parent[i] < i){
            cout << parent[i] << " " << i << " " << edge[i][parent[i]]; 
        }else{
            cout << i << " " << parent[i] << " " << edge[i][parent[i]];
        }
        
    }
    
    
    
    delete [] parent;
    delete [] weight;
    delete [] visited;

    
}







int main(){
    int n, e; // no. of vertices and no. of edges
    cin >> n >> e;

    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0; i<e; i++){
        int fv, sv, weight; 
        cin >> fv >> sv >> weight;
        edges[fv][sv] = weight;
        edges[sv][fv] = weight;
    }
    
    
    prims(edges, n);
    
    
    // delete the adjacency matrix
    for(int i=0; i<n; i++){
        delete [] edges[i];
    }
    
    delete [] edges;

}












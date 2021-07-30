#include <iostream>
#include <climits>
using namespace std;


int findMinVertex(int* weight, bool* visited, int n){
    
    int minVertex = -1; // initialize the answer to be returned with -1
    
    for(int i=0; i<n; i++){
// initially when we enter loop, minVertex = -1. so in the second condition we cant access weight[minVertex]. so initially when we enter the loop, we want to directly update minVertex to be the first vertex
        if(visited[i] == false && (minVertex == -1 || weight[i] < weight[minVertex])){
            minVertex = i;
        }
    }
    
    return minVertex;
}






// takes in a graph and print its MST
void prims(int** edges, int n){
    int* parent = new int[n];    // to store parent of each vertex
    int* weight = new int[n];    // weight stores weight of each vertex
    bool* visited = new bool[n];  // to store if a vertex has been visited or not
    
    // run a loop to initialize the values of all arrays for all vertices
    for(int i=0; i<n; i++){
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    
    // assume the 0th vertex to be the source vertex. hence:
    parent[0] = -1;
    weight[0] = 0;
    
    // run a for loop to travel on all the vertices
    for(int i=0; i<n; i++){
        // select the vertex with minimum weight from the unvisited vertices
        int minVertex = findMinVertex(weight, visited, n);
        
        // mark minVertex to be visited
        visited[minVertex] = true;
        
        // explore unvisited neighbours of minVertex
        // use adjacency matrix to find neighbout
        for(int j=0; j<n; j++){
            if(edge[minVertex][j] != 0 && visited[j] == false){
                if(edge[minVertex][j] < weight[j]){
                    weight[j] = edge[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    
    // the MST is ready. now we need to print it
    // there are v-1 edges in the MST so run a for loop v-1 times
    for(int i=1; i<v; i++){
        if(parent[i] < i){
            cout << parent[i] << " " << i << " " << edge[i][parent[i]]; // print both the vertices and weight of edge connecting both of them. or we can do << weight[i] cuz the weight of edge connecting parent and i = weight of vertex i because of the algorithm.
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
    
    // create adjacency matrix and initialize all cells with 0 - meaning no edge bw those 2 vertices
    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }
    
    // take input of the edges and fill the adjacency matrix
    for(int i=0; i<e; i++){
        int fv, sv, weight; // first vertex, second vertex, weight of the edge connnecting sv and ev
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












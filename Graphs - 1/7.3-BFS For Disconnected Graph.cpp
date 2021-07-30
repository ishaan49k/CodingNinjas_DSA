#include<iostream>
using namespace std;
#include<queue>

void printBFS1(int** edges, int n, int sv, bool* visited){
    // queue stores vertices which we have seen but not printed yet
    queue<int> pendingVertices;
    
    // first push the starting vertex into the queue
    pendingVertices.push(sv);
    visited[sv] = true;
    
    // keep printing while queue dosent become empty
    while(!pendingVertices.empty()){
        // print the vertex at front of queue
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << endl;
        
        // add all vertices which are adj to current vertex in queue
        for(int i=0; i<n; i++){
            if(i == currentVertex){
                continue;
            }
            
            // if there is an edge bw currentVertex and ith vertex and ith has not been visisted yet, ad dit to the queue
            if(edges[currentVertex][i] == 1 && visited[i] == false){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}


void printBFS2(int** edges, int n){
    // create visited array
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
    // call function that prints only connected graph - printDFS1
    // iterate through all vertices. if any is not visited, call DFS1 on it
    for(int i=0; i<n; i++){
        if(visited[i] == false){
            printBFS1(edges, n, i, visited);
        }
    }
    
    delete [] visited;
    
}





int main(){

// first create the graph by entering no. of vertices and no. of edges
    int n;
    int e;
    cin >> n >> e;
    
// to store all the edges, create a 2D array of size n * n
// we could have filled bools in it but for now, use 0 and 1 to check connection
    int** edges = new int* [n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        // initialize the entire column we added above with 0's
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }

// user will now tell us which edges are connected
    for(int i=0; i<e; i++){
        int f; // first vertex
        int s; // second vertex
        cin >> f >> s;
        // make connection by putting 1
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    
    // it takes in adj matrix, its size, start vertex and array of visted indexes
    printBFS2(edges, n);
    
    // Delete all the memory
    for(int i=0; i<n; i++){
        delete [] edges[i];
    }
    delete [] edges;
    
}






















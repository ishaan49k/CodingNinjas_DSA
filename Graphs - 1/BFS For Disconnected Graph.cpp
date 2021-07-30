#include<iostream>
using namespace std;
#include<queue>

void printBFS1(int** edges, int n, int sv, bool* visited){
    queue<int> pendingVertices;
    

    pendingVertices.push(sv);
    visited[sv] = true;
    

    while(!pendingVertices.empty()){

        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << endl;
        

        for(int i=0; i<n; i++){
            if(i == currentVertex){
                continue;
            }

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

    int** edges = new int* [n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
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

    

    printBFS2(edges, n);
    
    // Delete all the memory
    for(int i=0; i<n; i++){
        delete [] edges[i];
    }
    delete [] edges;
    
}






















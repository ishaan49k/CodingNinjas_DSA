
#include<iostream>
using namespace std;


void printDFS1(int** edges, int n, int sv, bool* visited){
    // print the starting vertex
    cout << sv << endl;
    // after printing, mark that vertex as visited
    visited[sv] = true;
    
    for(int i=0; i<n; i++){
        // every vertice is connected to itself. so continue
        if(i==sv){
            continue;
        }
        if(edges[sv][i] == 1){
            // before printing, check if vertice has already been visited.
            if(visited[i]){
                continue;
            }
            printDFS1(edges, n, i, visited);
        }
    }
}


void printDFS2(int** edges, int n){
    // create visited array
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
    // call function that prints only connected graph - DFS1
    // iterate through all vertices. if any is not visited, call DFS1 on it
    for(int i=0; i<n; i++){
        if(visited[i] == false){
            printDFS1(edges, n, i, visited);
        }
    }
    
    delete [] visited;
}


// printDFS1 is the origional DFS printing fxn which prints only connected graphs
// printDFS2 is new fxn which prints disconnected graphs using printDFS1

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

    
    // it takes in adj matrix, size only.
    printDFS2(edges, n);
    
    // Delete all the memory
    for(int i=0; i<n; i++){
        delete [] edges[i];
    }
    delete [] edges;
    
}






















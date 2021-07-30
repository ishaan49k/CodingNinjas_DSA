
#include<iostream>
using namespace std;


void printDFS1(int** edges, int n, int sv, bool* visited){
    // print the starting vertex
    cout << sv << endl;
    visited[sv] = true;
    
    for(int i=0; i<n; i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i] == 1){
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

    for(int i=0; i<n; i++){
        if(visited[i] == false){
            printDFS1(edges, n, i, visited);
        }
    }
    
    delete [] visited;
}




int main(){
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

    for(int i=0; i<e; i++){
        int f; // first vertex
        int s; // second vertex
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    
    printDFS2(edges, n);
    
    // Delete all the memory
    for(int i=0; i<n; i++){
        delete [] edges[i];
    }
    delete [] edges;
    
}






















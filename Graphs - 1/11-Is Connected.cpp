#include<iostream>
using namespace std;


void DFS(bool** graph, int v, bool* visited, int currentVertex){
    // we have visited the currentVertex. so mark it as visited
    visited[currentVertex] = true;
    
    // call DFS on all the vertices adjacent to currentVertex
    for(int i=0; i<v; i++){
        if(i == currentVertex){
            continue;
        }
        if(graph[currentVertex][i] && visited[i] == false){
            DFS(graph, v, visited, i);
        }
    }
}




bool isConnected(bool** graph, int v){
    // created a visited array
    bool* visited = new bool[v];
    
    // perform DFS traversal on the graph starrting from the 0th vertex
    DFS(graph, v, visited, 0);
    
    // now DFS is complete and the visisted array has been filled. check if there is even one false in it. if there is, graph is disconnected
    for(int i=0; i<v; i++){
        if(visited[i] == false){
            return false;
        }
    }
    
    return true;
}




int main(){
    // create a grah and pass it in the isConnected function
    
    
    
    
}

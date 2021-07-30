#include<iostream>
using namespace std;


void DFS(bool** graph, int v, bool* visited, int currentVertex){

    visited[currentVertex] = true;

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
    

    DFS(graph, v, visited, 0);
    
   
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

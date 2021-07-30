#include <iostream>
using namespace std;



void DFS(bool** graph, int v, int sv, booll* visited){
    visited[sv] = true;
    
    // DFS on all vertices adj to sv:
    for(int i=0; i<v; i++){
        if(graph[sv][i] && visited[i] == false){
            DFS(graph, v, i, visited);
        }
    }
    
}






int getIslandGroups(bool** graph, int v){
    //create a visited array
    bool* visited = new bool[v]();
    
    int groupCount = 0; // this is the final answer we need to return
    
    // iterate on all vertices and call DFS on all of them
    for(int i=0; i<v; i++){
        if(visited[i] == false){
            DFS(graph, v, i, visited);
            groupCount++;
        }
    }
    
    return groupCount;
    
}





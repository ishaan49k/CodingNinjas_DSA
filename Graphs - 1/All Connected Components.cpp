#include <iostream>
using namespace std;
#include <vector>
#include <queue>


vector<int> getOneComponent(bool** grah, int v, int sv, bool* visited){

    vector<int> component;
    

    queue<int> pendingVertices;
    
    pendingVertices.push(sv);
    visited[sv] = true;
    
    while(!pendingVertices.empty()){
        int front = pendingVertices.front();
        pendingVertices.pop();
        component.push_back(front);
        // add all vertices adjacent to front to the queue
        for(int i=0; i<v; i++){
            if(graph[front][i] && visited[i] == false){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    
    return component;
}




vector<vector<int>> getAllComponents(bool** graph, int v){
    vector<vector<int>> answer; 
    
    // create a visited array
    bool* visited = new bool[v]();
    
    // iterate through all vertices and call getOneComponent on the vertices which are not visited yet
    for(int i=0; i<v; i++){
        if(visited[i] == false){
            vector<int> component = getOneComponent(graph, v, i, visited);
            answer.push_back(component); // add the component to the answer vector
        }
    }
    
    delete [] visited;
    
    return answer;
    
}



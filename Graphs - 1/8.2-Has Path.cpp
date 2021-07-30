// Final code
# include <iostream>
using namespace std;


bool hasPathHelper(bool** graph, int v, int sv, int ev, bool* visited){
   // base case: check if sv and ev are same. if yes, return true
    if(sv == ev){
        return true;
    }
    
    // here, sv != ev. mark sv as visited and call recursion on all vertices adjacent to sv
    visited[sv] = true;
    
    // call recursion on vertices adjacent to sv:
    for(int i=0; i<v; i++){
        if(graph[sv][i] == true && visited[i] == false){
            if(hasPathHelper(graph, v, i, ev, visited)){ // if recursion finds a path, return true
                return true;
            }
        }
    }
    
    // if we reach here, it means recursion has not found a path. so there is no path
    return false;
    
}








// since we need a visited array as argument also when we call recursion, create a helper fxn which has additionla argument as visited array
bool hasPath(bool** graph, int v, int sv, int ev){
    // create a visited array
    bool* visited = new bool[v];
    
    return hasPathHelper(graph, v, sv, ev, visited);
    
    delete [] visited;
    
}





// create a grpah and pass it into the function
int main(){
    int v; // no. of vertices in graph
    int e; // no. of edges in graph
    cin >> v;
    cin >> e;
    
    bool** graph = new bool*[v];
    for(int i=0, a, b; i<e; i++){ // create 2 integers a and b which help us fill the 2D array
        cin >> a;
        cin >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    
    int startVertex;
    int endVertex;
    cin >> startVertex;
    cin >> endVertex;
    
    // call the function hasPath to check if startVertex and endVertex are connected
    if(hasPath(graph, v, startVertex, endVertex)){
        return true;
    }else{
        return false;
    }
    
    // delete the graph
    for(int i=0; i<v; i++){
        delete [] graph[i];
    }
    
    delete [] graphs;
    
}























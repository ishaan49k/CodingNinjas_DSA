// Final code
# include <iostream>
using namespace std;


bool hasPathHelper(bool** graph, int v, int sv, int ev, bool* visited){
    if(sv == ev){
        return true;
    }
    visited[sv] = true;
    
    for(int i=0; i<v; i++){
        if(graph[sv][i] == true && visited[i] == false){
            if(hasPathHelper(graph, v, i, ev, visited)){
                return true;
            }
        }
    }
    
    return false;
    
}


bool hasPath(bool** graph, int v, int sv, int ev){

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
    for(int i=0, a, b; i<e; i++){
        cin >> a;
        cin >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    
    int startVertex;
    int endVertex;
    cin >> startVertex;
    cin >> endVertex;

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























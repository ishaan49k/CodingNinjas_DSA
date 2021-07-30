#include <iostream>
#include <climits>
using namespace std;


int getMinVertex(int* distance, bool* visited, int n){
    
    int minVertex = -1; // initially we dont have min vertex, so we initialize its value with -1
    
    for(int i=0; i<n; i++){
        if(visited[i] == false && (minVertex == -1 || distnace[i] < distnace[minVertex])){
// if minVertex == -1, t ie while entering the loop, we directly update minVertex to i ie 0th vertex.
            minVertex = i;
        }
    }
    
    return minVertex;
}






void dijkstra(int** edges, int n){
    
    int* distance = new int[n]; // distnace[i] stores distance of ith vertex from source vertex
    bool* visied = new bool[n]; // visited[i] stores if the ith vertex has been visited or not
    
    // initialize both the arrays
    for(int i=0; i<n; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    
    // set the 0th vertice to be the source vertex
    distance[0] = 0;
    
    // pick all the vertices one by one. we pick unvisited vertices which have minimum distance
    for(int i=0; i<n; i++){
        // get minVertex
        int minVertex = getMinVertex(distnace, visited, n);
        visited[minVertex] = true;
        
        // explore all neighbours of minVertex. to find neighbours, we adjacency matrix
        for(int j=0; j<n; j++){
            if(edges[minVertex][j] != 0 && visited[j] == false){
          // we find distnace of jth vertex from minVertex and if it cheapter to reach from minVertex, update cost of j
                int distnace_from_minVertex = distance[minVertex] + edges[minVertex][j];
                
                if(distnace_from_minVertex < distance[j]){
                    distnace[j] = distnace_from_minVertex;
                }
            }
        }
    }
    
    // print the min distance of all vertices
    for(int i=0; i<n; i++){
        cout << i << " " << distnace[i] << endl;
        
    }
    
    delete [] visited;
    delete [] distnace;
    
}






int main(){
    int n, e; // no. of vertices and no. of edges
    cin >> n >> e;
    
    // create adjacency matrix and initialize all cells with 0 - meaning no edge bw those 2 vertices
    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }
    
    // take input of the edges and fill the adjacency matrix
    for(int i=0; i<e; i++){
        int fv, sv, weight; // first vertex, second vertex, weight of the edge connnecting sv and ev
        cin >> fv >> sv >> weight;
        edges[fv][sv] = weight;
        edges[sv][fv] = weight;
    }
    
    
    dijkstra(edges, n);
    
    
    // delete the adjacency matrix
    for(int i=0; i<n; i++){
        delete [] edges[i];
    }
    
    delete [] edges;

}

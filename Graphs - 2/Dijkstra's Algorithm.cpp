#include <iostream>
#include <climits>
using namespace std;


int getMinVertex(int* distance, bool* visited, int n){
    
    int minVertex = -1; 
    
    for(int i=0; i<n; i++){
        if(visited[i] == false && (minVertex == -1 || distnace[i] < distnace[minVertex])){
            minVertex = i;
        }
    }
    
    return minVertex;
}






void dijkstra(int** edges, int n){
    
    int* distance = new int[n]; 
    bool* visied = new bool[n];
    

    for(int i=0; i<n; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[0] = 0;
    

    for(int i=0; i<n; i++){
        // get minVertex
        int minVertex = getMinVertex(distnace, visited, n);
        visited[minVertex] = true;
        

        for(int j=0; j<n; j++){
            if(edges[minVertex][j] != 0 && visited[j] == false){

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
    

    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }
    

    for(int i=0; i<e; i++){
        int fv, sv, weight; 
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

#include <iostream>
using namespace std;


class Edge{
public:
    int source; 
    int dest;   
    int weight;  
     
};




int findParent(int* v, int* parent){

    if(parent[v] == v){
        return v;
    }
   
    return findParent(parent[v], parent);
    
}





bool compare(Edge e1, Edge e2){
    return e1.weight < e2.weight; 
   
}





void kruskals(Edge* input, int n, int e){
    sort(input, input + e, compare); 
    
    Edge* output = new Edge[e-1];
    
    int* parent = new int[n];
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    
    int count = 0;
    int i = 0; 
    
    while(count != e-1){
        Edge currentEdge = input[i];
        

        int p1 = findParent(currentEdge.source, parent);           
        int p2 = findParent(currentEdge.dest, parent);      
        
        if(p1 != p2){  
            output[count] = currentEdge;
            parent[p1] = p2;                
            count ++;
        }
        
        i++; 
        
    }

    for(int i=0; i<e-1; i++){
        if(output[i].source < output[i].dest){
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
        }else{
            cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
        }
        
    }
    
    
}





int main(){

    int n;
    int e;
    cout << "enter no. of vertices " << endl;
    cin >> n;
    cout << "enter no. of edges " << endl;
    cin >> e;
    
    Edge* input = new Edge[e];
    // take input:
    for(int i=0; i<e; i++){
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s; 
        input[i].dest = d;
        input[i].weight = w;
    }

    
    kruskals(input, n, e);
    
}


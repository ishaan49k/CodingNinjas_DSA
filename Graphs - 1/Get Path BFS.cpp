#include<iostream>
using namespace std;
#include "vector"
#include "queue"
#include "unordered_map"


vector<int>* getPath(int** edges, int n, int sv, int ev){

    queue<int> bfsQueue;

    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    bfsQueue.push(sv);
    visited[sv] = true;

    bool done = false; 
    unordered_map<int, int> parent;  
    
    while(!bfsQueue.empty() && !done){
        int front = bfsQueue.front();
        bfsQueue.pop();

        for(int i=0; i<n; i++){
            if(edges[front][i] && visited[i] == false){
                parent[i] = front; 
                bfsQueue.push(i);

                visited[i] = true;
                

                if(i == ev){ 
                    done = true; 
                    break; 
                }
            }
        }
        delete [] visited;
        
        
        if(!done){   
            return NULL;
            
        }else{ 
            vector<int>* output = new vector<int>();
            int current = ev; 
            output->push_back(current);

            while(current != sv){
                current = parent[current];
                output->push_back(current);
            }
            
            return output;
            
        }
    }
}




































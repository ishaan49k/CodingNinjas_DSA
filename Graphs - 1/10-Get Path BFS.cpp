#include<iostream>
using namespace std;
#include "vector"
#include "queue"
#include "unordered_map"

// n - no. of vertices
vector<int>* getPath(int** edges, int n, int sv, int ev){
    // use a queue. keep adding vertices to queue til we reach end vertex
    queue<int> bfsQueue;
    
    // create visited array
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
    // since we pushed sv in queue, mark sv as visited
    bfsQueue.push(sv);
    visited[sv] = true;
    
    // keep working until queue becomes empty
    bool done = false; // flag variable used to break while loop when we reach ev
    unordered_map<int, int> parent;  // map stores which vertex added which vertex to queue
    
    while(!bfsQueue.empty() && !done){
        int front = bfsQueue.front();
        bfsQueue.pop();
        
        // now one by one go to every vertice and check if it is adj to front
        for(int i=0; i<n; i++){
            if(edges[front][i] && visited[i] == false){ // cuz if i has been already put in queue, we dont put it in queu again
                parent[i] = front; //when we add vertex to queue, emter which vertex added it in the map. front adds i to the queue
                bfsQueue.push(i);
                // since we put it in queue, mark it as visited
                visited[i] = true;
                
                // now check if the vertex we inseerted in queue is the ev. as soon as we reach ev, no need to add more vertexes to queue, so we break
                if(i == ev){ // we have reached our destination
                    done = true; // mark done true when we reach ev
                    break; // this break will only break while. we want to break out of for also cuz our entire work is done. this is why we have defined the flag variable done.
                }
            }
        }
        delete [] visited; // dont need current anymore
        
        // the while loop can break due to 2 reasons - 1. we travel to all vertices and we dont find ev(in this case we break cuz queue becomes empty ) or we find ev
        if(!done){   // done is false if we dont find ev so return NULL
            return NULL;
        }else{ // we each ev. now we need to obtain path of the vertice
            vector<int>* output = new vector<int>();
            int current = ev; // the current vertex we are on in adding path to vector is ev. we are adding path from ev to sv
            output->push_back(current);
            
            // keep adding path to vector until we reach sv
            while(current != sv){
                current = parent[current]; // new current is the vertex which added current to the queue
                output->push_back(current);
            }
            
            return output;
            
        }
    }
}




























































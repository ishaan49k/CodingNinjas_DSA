#include<bits/stdc++.h>

// Final code
// in this soln, we first insert all the elements of all the arrays in to the pq and then build the ans vector
vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    
    priority_queue <int, vector<int>, greater<int>> pq; // min pq
    
    for(int i=0 ; i<input.size() ; i++){  // iterate over every array
        for(int j=0; j<input[i]->size(); j++){
            pq.push(input[i]->at(j));
        }
    }
 	
    vector<int> ans;
    
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    
    return ans;
}


---------------------------------------------------------------------------------------------------------------

// Final code
// In this method, we use a triplet 

typedef pair<int, pair<int, int> > ppi;

vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    
    vector<int> ans; 
    
    // priority queue will store min ele of array, index of array and index of ele in array
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq; // create a min priority queue
    
	// iterate over all arrays and fill initial values
    for(int i=0; i<input.size(); i++){
        pq.push(input[i][0], {i, 0});
    }
    
    while(!pq.empty()){
        ppi curr = pq.top();
        pq.pop();
        
        // i=> array number
        // j=> index of element in array
        int i = curr.second.first;
        int j = curr.second.second;
        
        // add the min element to ans
        ans.push_back(curr.first);
        
        // add the next element of current array into the pq
        if(j+1 < input[i].size()){
            pq.push(input[i][j], {i, j+1})
        }
        
    }
    
    return ans;
    
    
    
    
    
}








// Final solution

#include <vector>
#include<queue>

vector<int> kLargest(int input[], int n, int k){
    
    // pq will store k largest elements
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // put first k elemenst of array in pq
    for(int i=0; i<k; i++){
        pq.push(input[i]);
    }
    
    // iterate on remaining n-k elemets and compare each with smallest in pq
    for(int i=k; i<n; i++){
        if(input[i] > pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
    }
    
    // now we have k largest elemensts stored in pq. copy them in a vector
    vector<int> output;
    
    while(pq.size() != 0){
        output.push_back(pq.top());
        pq.pop();
    }
    
    return output;
    
    
}













































































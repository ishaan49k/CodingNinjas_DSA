// Final solution

#include <queue>
vector<int> kSmallest(int arr[], int n, int k){
    // the pq max stores k smallest elements
    priority_queue<int> min;
    
    // insert first k elemensts into the pq
    for(int i=0; i<k; i++){
        min.push(arr[i]);
    }
    
    // loop runs on the remaining n-k elements of the array
    for(int i=k; i<n; i++){
        if(arr[i] < min.top()){
            min.pop();
            min.push(arr[i]);
        }
    }
    
    // now max stores the k smallest elements of the array
    
    // transfer all elements from the pq to vector
    vector<int> output;
    
    while(min.size() != 0){
        output.push_back(min.top());
        min.pop();
    }
    
    return output;
    
}


//Final code.
#include <queue>
int kthLargest(int* arr, int n, int k){
    
    // to find largest element, use min priority queue
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // add first k elements to min heap.
    for(int i=0; i<k; i++){
        minHeap.push(arr[i]);
    }
    
    for(int i=k; i<n; i++){
        if(arr[i] > minHeap.top()){
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    
    return minHeap.top();
    
}




































































































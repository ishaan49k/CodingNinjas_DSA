#include<queue>
void printRunningMedian(int* arr, int n){
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int i=0; i<n; i++){
        if(maxHeap.size() == 0 || arr[i] < maxHeap.top()){
            maxHeap.push(arr[i]);
        }else{
            minHeap.push(arr[i]);
        }
        if((int)maxHeap.size() - (int)minHeap.size() > 1){
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }
        if((int)minHeap.size() - (int)maxHeap.size() > 1){
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }

        int median;
        int totalSize = minHeap.size() + maxHeap.size();
        if(totalSize % 2 != 0){
            if(maxHeap.size() > minHeap.size()){
                median = maxHeap.top();
            }else{
                median = minHeap.top();
            }
        }else{
            median = 0; // initialize it
            median += maxHeap.top();
            median += minHeap.top();
            median = median/2;
        }
           
        cout << median << ' ';
    }
}























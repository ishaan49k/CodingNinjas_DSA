#include<queue>
void printRunningMedian(int* arr, int n){
    // create min and max heaps
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // iterate over every element in the array
    for(int i=0; i<n; i++){
        // push ele into min heap if size of min heap == 0 or ele is smaller than max of minheap. else in max heap
        if(maxHeap.size() == 0 || arr[i] < maxHeap.top()){
            maxHeap.push(arr[i]);
        }else{
            minHeap.push(arr[i]);
        }
        
        
        // after inserting ele, make sure the size of the 2 heaps dosent differ by more than 1
// .size() returns unsigned int so we cant subtract them without typecasting them into signed int
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
        

        // print the median after pushing the element into the correct heap
        int median;
        int totalSize = minHeap.size() + maxHeap.size();
        
        // when total number of elements is odd:
        if(totalSize % 2 != 0){
            if(maxHeap.size() > minHeap.size()){
                median = maxHeap.top();
            }else{
                median = minHeap.top();
            }
        }else{   // when no. of elements is even:
            median = 0; // initialize it
            median += maxHeap.top();
            median += minHeap.top();
            median = median/2;
        }
           
        cout << median << ' ';
    }
}

























#include<queue>


int buyTicket(int *arr, int n, int k){
    queue<int> peopleQueue; 
    
    priority_queue<int> maxHeap; 
    for(int i=0; i<n; i++){
        peopleQueue.push(i);
        maxHeap.push(arr[i]);
    }
    
    int time = 0;
    
    while(!maxHeap.empty()){
        int high = maxHeap.top();
        int front = peopleQueue.front();
        if(front==k && arr[k]==high){
            time++;
            return time;
        }
        if(arr[front]==high){
            time++;
            peopleQueue.pop();
            maxHeap.pop();
        }else{
            peopleQueue.pop();
            peopleQueue.push(front);
        }
    }
    
}





















// Final code
#include<queue>

//given list of priorities of n people and index of our priority(k)
int buyTicket(int *arr, int n, int k){
    queue<int> peopleQueue; // stores indexes of the people in line to get ticket
    
    priority_queue<int> maxHeap; // stores the priorities of all the people in the queue
    
    // enter all data into queue and priority queue
    for(int i=0; i<n; i++){
        peopleQueue.push(i);
        maxHeap.push(arr[i]);
    }
    
    int time = 0; // this is the final answer to be returned
    
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





















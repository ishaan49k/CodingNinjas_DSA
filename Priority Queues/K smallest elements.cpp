#include <queue>
vector<int> kSmallest(int arr[], int n, int k){
    priority_queue<int> min;
    for(int i=0; i<k; i++){
        min.push(arr[i]);
    }
    for(int i=k; i<n; i++){
        if(arr[i] < min.top()){
            min.pop();
            min.push(arr[i]);
        }
    }
    vector<int> output;
    
    while(min.size() != 0){
        output.push_back(min.top());
        min.pop();
    }
    
    return output;
    
}


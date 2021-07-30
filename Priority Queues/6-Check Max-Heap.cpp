// Final code.
bool isMaxHeap(int arr[], int n){
    // we need to compare the parent with each of its children:
    // we should not try to access children indexes of a leaf node.
    // so break the loop for an index i which dosent have any children.
    for(int i=0; 2*i+1<n; i++){  // ie while left child exists
        int leftChildIndex = 2*i+1;
        int rightChildIndex = leftChildIndex+1;
        
        // compare the left child:
        if(arr[i] < arr[leftChildIndex]){
            return false;
        }
        
        // compare the right child:
        if(rightChildIndex < n && arr[i] < arr[rightChildIndex]){
            return false;
        }
    }
    
    return true;
    
}





































































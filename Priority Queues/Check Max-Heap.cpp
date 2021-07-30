bool isMaxHeap(int arr[], int n){
    for(int i=0; 2*i+1<n; i++){
        int leftChildIndex = 2*i+1;
        int rightChildIndex = leftChildIndex+1;

        if(arr[i] < arr[leftChildIndex]){
            return false;
        }

        if(rightChildIndex < n && arr[i] < arr[rightChildIndex]){
            return false;
        }
    }
    
    return true;
    
}





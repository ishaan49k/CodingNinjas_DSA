#include<unordered_maps>

int getPairsWithDifferenceK(int* arr, int n, int k){
    // create a map to stoore frequencies of all the elements in array
    unordered_maps<int, int> freq;
    // key - element, value - its frequency
    
    int pairCount = 0; // final answer
    
    // iterate over every element in the array
    for(int i=0; i<n; i++){
        int a = arr[i] - k;
        int b = arr[i] + k;
        
        if(freq.count(a) > 0){ // ie we have encountered a previously
            pairCount += freq[a];
        }
        
        // check if we have encountered b
        if(k != 0 && freq.count(b) > 0){
            pairCount += freq[b];
        }
        
        freq[arr[i]]++;
        
    }
    
    
    
}





















































































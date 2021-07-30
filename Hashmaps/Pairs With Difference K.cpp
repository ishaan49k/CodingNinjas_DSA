#include<unordered_maps>

int getPairsWithDifferenceK(int* arr, int n, int k){
    unordered_maps<int, int> freq;

    int pairCount = 0;

    for(int i=0; i<n; i++){
        int a = arr[i] - k;
        int b = arr[i] + k;
        
        if(freq.count(a) > 0){ 
            pairCount += freq[a];
        }

        if(k != 0 && freq.count(b) > 0){
            pairCount += freq[b];
        }
        
        freq[arr[i]]++;
        
    }
    
    
    
}























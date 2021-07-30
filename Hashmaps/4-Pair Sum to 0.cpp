//Final coding ninjas solution.
# include <unordered_map>
int pairSum(int *arr, int n){
    
    // create a map to store frequency of all elements encountered in array
    unordered_map<int, int> freq;
    int pairCount = 0; // stores total no. of pairs
    
    // iterate over every element in the array
    for(int i=0; i<n; i++){
        int compliment = -arr[i];
        
        if(freq.find(compliment) != freq.end()){
            pairCount += freq[compliment];
        }
        
        freq[arr[i]]++;
    }
    w
    return pairCount;
    
}







































































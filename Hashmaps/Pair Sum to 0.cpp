# include <unordered_map>
int pairSum(int *arr, int n){
    unordered_map<int, int> freq;
    int pairCount = 0;
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


or
    
int pairSum(int *arr, int n){
    
    // create a hashmap to store freq of all elements
    unordered_map<int, int> mp;
    int pairs = 0;
    
    for(int i=0; i<n; i++){
        int compliment = -arr[i];
        
        if(mp.count(compliment)){
            pairs += mp[compliment];
        }
        
        mp[arr[i]]++;
        
    }
    
    return pairs;
    
    
    
}











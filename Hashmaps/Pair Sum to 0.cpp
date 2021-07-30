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












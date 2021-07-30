#include <unordered_map>

int highestFrequency(int arr[], int n){
    unordered_map<int, int> frequency;
    int maxFreq = 0;
    for(int i=0; i<n; i++){
        frequency[arr[i]]++; 
        maxFreq = max(maxFreq, frequency[arr[i]]);
    }
    int maxFreqEle;
    for(int i=0; i<n; i++){
        if(frequency[arr[i]] == maxFreq){
            maxFreqEle = arr[i];
            break;
        }
    }
    
    return maxFreqEle;
    
}











// Final solution

#include <unordered_map>

int highestFrequency(int arr[], int n){
    // use a map to keep track of frequency of each number:
    unordered_map<int, int> frequency;
    int maxFreq = 0;
    
// travel the array and find the frequency of each number.
    for(int i=0; i<n; i++){
        frequency[arr[i]]++; // use [] cuz if the ele is not there in map, then it gets added.
        // compare freq of current ele with maxFreq and update if required.
        maxFreq = max(maxFreq, frequency[arr[i]]);
    }
    
    // find the ele with highest frequency by travelling the array;
    int maxFreqEle;
    for(int i=0; i<n; i++){
        if(frequency[arr[i]] == maxFreq){
            maxFreqEle = arr[i];
            break;
        }
    }
    
    return maxFreqEle;
    
}




































































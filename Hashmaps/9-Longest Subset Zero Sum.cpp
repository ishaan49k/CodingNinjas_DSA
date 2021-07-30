#include<unordered_map>


int lengthOfLongestSubsetWithZeroSum(int* arr, int n){
    // key - cumalative sum, value - iindex at which first time the sum occured
    unordered_map<int, int> map;
    
    int sum = 0;
    int maxLen = 0; // this is the final answer
    
    // iterate over every ele in array
    for(int i=0; i<n; i++){
        sum += arr[i];  // add current ele to the cumalative sum
        
//if sum=0, the subarray frm starting to current index is giving sum 0 cuz we started at 0 index with sum 0 and now e got 0 sum again. in this case, maxLen = i+1 cuz definatly this is going to be the largest subarray
        if(sum == 0){
            maxLen = i + 1;
        }else{ // is the sum is not 0, we check if we have encountered this sum before or not
            if(map.count(sum) > 0){ // if the sum already exixts
                int firstIndex = map[sum]; // get the fistIndex where this sum occurs
                int ans = i - firstIndex;  // get lenght of subarray
                if(ans > maxLen){
                    maxLen = ans;
                }
            }else{ // first time we encounter this sum. just put it in the map
                map[sum] = i;
            }
        }
    }
    
    return maxLen;
    
}























































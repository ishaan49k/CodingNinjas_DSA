#include<unordered_map>


int lengthOfLongestSubsetWithZeroSum(int* arr, int n){
    unordered_map<int, int> map;
    
    int sum = 0;
    int maxLen = 0; // this is the final answer

    for(int i=0; i<n; i++){
        sum += arr[i]; 
        

        if(sum == 0){
            maxLen = i + 1;
        }else{ 
            if(map.count(sum) > 0){ 
                int firstIndex = map[sum]; 
                int ans = i - firstIndex;  
                if(ans > maxLen){
                    maxLen = ans;
                }
            }else{ 
                map[sum] = i;
            }
        }
    }
    
    return maxLen;
    
}










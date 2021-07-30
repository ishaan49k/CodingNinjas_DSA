// Final code

#include<vector>
#include<unordered_map>

vector<int> longestConsecutiveIncreasingSequence(int* arr, int n){
    
    unordered_map<int, bool> visited; // stores all the elements we have encountered
    // initialize the map
    unordered_map<int,int> index;
    for(int i=0; i<n; i++){
        visited[arr[i]] = true;
        index[arr[i]] = i;
    }
    
    vector<int> output; // stores the final answer
    
    int maxLenght = 0;
    int startindex = -1;
    
    // iterate over every element in the array:
    for(int i=0; i<n; i++){
        int curr = arr[i];
        int currStartIndex = i;
        int count = 0;
        int tempcurr = curr-1;
        
        // check forward:
        while(visited[curr]==true){
            count++;
            visited[curr] = false;
            curr++;
        }
        // check backward
        while(visited[tempcurr]==true){
            count++;
            visited[tempcurr] = false;
            currStartIndex = index[tempcurr];
            tempcurr--;
        }
        
        // count greater then length
        if(count>maxLenght){
            maxLenght = count;
            startindex = currStartIndex;
        }
        else if(count==maxLenght){
            if(currStartIndex<startindex)
                startindex = currStartIndex;
        }
    }
    
    output.push_back(arr[startindex]);
    output.push_back(arr[startindex]+maxLenght-1);
    return output;
}




































































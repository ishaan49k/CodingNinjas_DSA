#include<vector>
#include<unordered_map>

vector<int> longestConsecutiveIncreasingSequence(int* arr, int n){
    
    unordered_map<int, bool> visited; 
    unordered_map<int,int> index;
    for(int i=0; i<n; i++){
        visited[arr[i]] = true;
        index[arr[i]] = i;
    }
    
    vector<int> output;
    
    int maxLenght = 0;
    int startindex = -1;

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

        while(visited[tempcurr]==true){
            count++;
            visited[tempcurr] = false;
            currStartIndex = index[tempcurr];
            tempcurr--;
        }

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




































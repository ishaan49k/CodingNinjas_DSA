// Final code

#include <unordered_map>
void intersection(int *arr1, int *arr2, int n, int m){
    
    // store frequency of all elements of arr1 in mp
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr1[i]]++;
    }
    
    // check if element of arr2 exists in mp
    sort(arr2, arr2 + m);  // did this step only so answer matches. without this is also fine
    for(int i=0; i<m; i++){
        if(mp.count(arr2[i])){
            cout << arr2[i] << " ";
            mp[arr2[i]]--;
            if(mp[arr2[i]] == 0){
                mp.erase(arr2[i]);
            }
        }
    }
    
    
}



//see editorial for last method in which question is solved using hashmaps
#include<iostream>
using namespace std;

#include<unordered_map>

void printIntersection(int*arr1, int size1, int *arr2, int size2){
    // create a map which stores frequencies of all elements in arr1
    unordered_map<int, int> freq;
    
    // loop through arr1 and fill in frequencies of all its elements
    for(int i=0; i<size1; i++){
        freq[arr1[i]]++;
    }
    
    // for every ele in arr2, search it in map
    for(int i=0; i<size2; i++){
        if(freq.count(arr2[i]) > 0){
            // this means arr[i] is common to both arrays. so print it.
            cout << arr2[i];
            // after printing, reduce the frequency count by one
            freq[arr2[i]] --;
            // if freq becomes 0, remove it from the map
            if(freq[arr2[i]] == 0){
                freq.erase(arr2[i]);
            }
        }
    }
    
    
}































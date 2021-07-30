
#include<iostream>
using namespace std;

#include<unordered_map>

void printIntersection(int*arr1, int size1, int *arr2, int size2){
    unordered_map<int, int> freq;
    for(int i=0; i<size1; i++){
        freq[arr1[i]]++;
    }
    for(int i=0; i<size2; i++){
        if(freq.count(arr2[i]) > 0){
            cout << arr2[i];
            freq[arr2[i]] --;
            if(freq[arr2[i]] == 0){
                freq.erase(arr2[i]);
            }
        }
    }
    
    
}



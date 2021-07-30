// Final code
using namespace std;
#include<iostream>
#include<queue>
#include<string>

// return a string which has all the unique characters
// we need to check quickly if a char has been seen before. for this use a map
string uniqueChar(string str){
    // this string will be the final string we need to return
    string output = "";
    
    // use a map to store if we have encountered the char or not
    unordered_map<char, bool> seen;
    
    // iterate over every char in the string
    for(int i=0; i<str.size(); i++){
        // if current char has already been encountered, move to next char
        if(seen.count(str[i]) > 0){
            continue;
        }else{
            output += str[i];
            seen[arr[i]] =true;
        }
    }
    
    return output;
    
    
    
}





























using namespace std;
#include<iostream>
#include<queue>
#include<string>

string uniqueChar(string str){

    string output = "";
    
    unordered_map<char, bool> seen;
    
    for(int i=0; i<str.size(); i++){
        if(seen.count(str[i]) > 0){
            continue;
        }else{
            output += str[i];
            seen[arr[i]] =true;
        }
    }
    
    return output;
    
    
    
}






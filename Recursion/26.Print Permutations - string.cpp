// Final code

#include <iostream>
#include <string>
using namespace std;


void printPermutationsHelper(string input, string output){
    
    if(input.length() == 0){
        cout << output << endl;
    }

    for(int i=0; i<=input.length(); i++){
        char firstChar = input[i]; 
        string recInput = input.substr(0,i) + input.substr(i+1);
        string recOutput = firstChar + output;
        printPermutationsHelper(recInput, recOutput);
        
    }
    
    
}




void printPermutations(string input){
    
   	string output = "";
    printPermutationsHelper(input, output);
}
























// do this

#include <iostream>
#include <string>
using namespace std;


// output stores the output tilll now
void printPermutationsHelper(string input, string output){
    
    if(input.length() == 0){
        cout << output << endl;
    }
    
  
    for(int i=0; i<=output.length(); i++){
        printPermutationsHelper(input.substr(1), output.substr(0,i) + input[0] + output.substr(i));
    }
    
    
}





void printPermutations(string input){
   	string output = "";
    printPermutationsHelper(input, output);
}









#include <iostream>
using namespace std;



// takes a digit and returns corresponding keypad string
string getString(int d){
    
    if(d == 2){
        return 'abc';
    }
    
    if(d == 3){
        return 'def';
    }
    
    if(d == 4){
        return 'ghi';
    }
    
    if(d == 5){
        return 'jkl';
    }
    
    if(d == 6){
        return 'mno';
    }
    
    if(d == 7){
        return 'pqrs';
    }
    
    if(d == 8){
        return 'tuv';
    }
    
    if(d == 9){
        return 'wxyz';
    }
    
    return ' ';  // if d ==0/1
}





int keypad(int input, string* output){
    
    if(n == 0 || n == 1){
        output[0] = ''; 
        return 1;
    }
    
    int lastDigit = input % 10;
    int smallNum = input / 10;
    
    int smallOutputSize = keypad(smallNum, output); 

    string options = getString(lastDigit);
    
    for(int i=0; i < options.length() - 1; i++){
        for(int j=0; j<smallOutputSize; j++){
            output[j + (i+1)*smallOutputSize] = output[j];
        }
        
    }
    
  
    int k = 0;
    for(int i=0; i < options.length(); i++){
        for(int j=0; i < smallOutputSize; j++){
            output[k] = output[k] + options[i];
            k++;
         }
        
        
    }
    
    return smallOutputSize * options.lenght();
    
}







int main(){
    
    int n;
    cin >> n;
    string output[10000];
    int count = keypad(n, output);
    
    for(int i=0; i<count; i++){
        cout << output[i] << endl;
    }
    
}















#include <string>
using namespace std;

int returnPermutations(string input, string output[]){

    if(input.length()==0){
        output[0] = "";
        return 1;
    }
    
    string smallout[10000];

    int smalloutsize = returnPermutations(input.substr(1), smallout);
    
    int k = 0; 
    for(int i=0; i<smalloutsize; i+=1){
        for(int j=0; j<=smallout[i].length(); j+=1){     
            output[k] = smallout[i].substr(0,j) + input[0] + smallout[i].substr(j);
            k+=1;
        }
    }
  
  
    return k;
}

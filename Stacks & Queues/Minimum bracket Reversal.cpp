#include<stack>
int countBracketReversals(string input){
    int lenght = input.length();
    if(lenght==0){
        return 0;
    }
    if(lenght%2!=0){
        return -1;
    }
    
    stack<char> stk;
    
    for(int i=0; i<lenght; i++){
        char currentEle = input[i];
        if(currentEle=='{'){ 
            stk.push(currentEle);
        }else{
            if(stk.empty()){
                stk.push(currentEle);
            }else if(stk.top()=='}'){
                stk.push(currentEle);
            }else{
                stk.pop();
            }
        }
    }
    
    int count = 0;
    while(!stk.empty()){
        char c1 = stk.top();
        stk.pop();
        char c2 = stk.top();
        stk.pop();
        
        if(c1==c2){
            count+=1;
        }else{
            count+=2;
        }
    }
    
    return count;
    
}




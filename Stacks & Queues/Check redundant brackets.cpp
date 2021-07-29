#include <stack>
bool checkRedundantBrackets(string exp){
    stack<char> stk;
    for(int i=0; i<exp.length(); i++){
        if(exp[i]!=')'){
            stk.push(exp[i]);
            continue;
        }
      
        int count = 0;
        while(stk.top()!='('){
            count+=1;
            stk.pop();
        }
        stk.pop();
        
        if(count<3){
            return true;
           }
    }
    
    return false;
}




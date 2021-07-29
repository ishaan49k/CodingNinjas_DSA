#include<stack>
#include<cstring>
bool isBalanced(string exp){
    stack<char> stk; 
    
    for(int i=0; exp[i]!='\0'; i++){

        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            stk.push(exp[i]);
        }else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){ 

            if(stk.empty()){
                return false; 
            }
            char ch = stk.top(); 
            stk.pop();
            if(exp[i]==')' && ch=='('){
                continue;
            }else if(exp[i]==']' && ch=='['){
                continue;
            }else if(exp[i]=='}' && ch=='{'){
                continue;
            }else{
                return false;
            }
        }
    }
    
    if(stk.empty()){
        return true;
    }else{
        return false;
    }
}


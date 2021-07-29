
#include<stack>
int* stockSpan(int *price, int size){
    stack<int> stk; // push indexes into this stack
    
    int* span = new int[size];  // array in which we store span
    
    for(int i=0; i<size; ++i){
        if(i==0){
            stk.push(i);
            span[i] = 1;
            continue;
        }                                                  
        while(!stk.empty() && price[i]>price[stk.top()]){ 
            stk.pop();                                
        }
        
        if(stk.empty()){
            span[i] = i+1;
        }else{
            span[i] = i - stk.top();
        }
        
        stk.push(i);
    }
    
    return span;
    
}




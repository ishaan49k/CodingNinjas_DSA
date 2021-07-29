void reverseStack(stack<int> &input, stack<int> &extra){
    if(input.empty() || input.size()==1){
        return;
    }
    
    int firstEle = input.top();
    input.pop();
 
    reverseStack(input, extra);
    while(!input.empty()){
        int ele = input.top();
        input.pop();
        extra.push(ele);
    }
    

    input.push(firstEle);

    while(!extra.empty()){
        int ele = extra.top();
        extra.pop();
        input.push(ele);
    }
    
    return;
}







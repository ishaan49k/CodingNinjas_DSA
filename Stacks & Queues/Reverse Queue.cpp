#include <bits/stdc++.h>
void reverseQueue(queue<int> &input){
    if(input.size()<=1){
        return;
    }
    
    int frontEle = input.front();
    input.pop();
    
    // Recursive call:
    reverseQueue(input);

    input.push(frontEle);
    return;

}

Node *swapNodes(Node *head, int i, int j){
    if(head==NULL || (i==j)){
        return head;
    }
    
    Node* currentNode = head;
    Node* prev = NULL;
    
    Node* firstNode = NULL;
    Node* firstNodeP = NULL;
    Node* secondNode = NULL;
    Node* secondNodeP = NULL;
    
    int pos = 0;
    while(currentNode!=NULL){
        if(pos==i){
            firstNodeP = prev;
            firstNode = currentNode;
        }else if(pos==j){
            secondNodeP = prev;
            secondNode = currentNode;
        }
        prev = currentNode;
        currentNode = currentNode->next;
        pos+=1;
    }
    
    if(firstNode!=NULL){
        firstNodeP->next = secondNode;
    }else{
        head = secondNode;
    }
    
    if(secondNodeP!=NULL){
        secondNodeP->next = firstNode;
    }else{
        head = firstNode;
    }
    
    Node* currentFirstNode = secondNode->next;
    secondNode->next = firstNode->next;
    firstNode->next = currentFirstNode;
    
    return head;
}

































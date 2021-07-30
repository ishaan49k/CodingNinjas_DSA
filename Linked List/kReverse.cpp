Node *kReverse(Node *head, int k){
    if(k==0 || k==1){
        return head;
    }
    
    Node* current  = head;
    Node* fwd = NULL;
    Node* prev = NULL;
    
    int count = 0;

    while(count<k && current!=NULL){
        fwd = current->next;
        current->next = prev;
        prev = current;
        current = fwd;
        count+=1;
    }
    
    if(fwd!=NULL){
        head->next = kReverse(fwd, k);
    }
    
    return prev;
}


























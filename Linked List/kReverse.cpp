Node *kReverse(Node *head, int k){
    if(k==0 || k==1){
        return head;
    }
    
    Node* current  = head;
    Node* f;          // forward 
    Node* p = NULL;   // previous
    int count = 0;
    while(count<k && current!=NULL){
        f = current->next;
        current->next = p;
        p = current;
        current = f;
        count+=1;
    }
    

    if(f != NULL){
        head->next = kReverse(f, k);
    }
    
    return p;
}


























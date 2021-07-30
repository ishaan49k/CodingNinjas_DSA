Node *reverseLinkedList(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* c = head;
    Node* n = head->next;
    Node* p = NULL;
    while(c!=NULL){
        n =c->next;
        c->next = p; 
        p = c;
        c = n;
       
    }
    return p;
}







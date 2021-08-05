Node *reverseLinkedList(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    Node* p = NULL;
    Node* c = head;
    Node* n;
    while(c != NULL){
        n = c->next;
        c->next = p; 
        p = c;
        c = n;
    }
    
    return p;
}




OR





Node *reverseLinkedList(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* c = head;
    Node* n = head->next;
    Node* p = NULL;
	while(n != NULL){
        c->next = p;
        p = c;
        c = n;
        n = n->next;
    }
    
    c->next = p;
    return c;
}










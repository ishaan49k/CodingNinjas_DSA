Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
    if(head1==NULL){
        return head2;
    }
    
    if(head2==NULL){
        return head1;
    }
    
    Node* fh = NULL;
    Node* ft = NULL;
    
    if(head1->data <= head2->data){
        ft = head1;
        fh = head1;
        head1 = head1->next;
    }else{
        ft = head2;
        fh = head2;
        head2 = head2->next;
    }
    
    while(head1!=NULL && head2!=NULL){
        if(head1->data <= head2->data){
            ft->next = head1;
            head1 = head1->next;
            ft = ft->next;
        }else{
            ft->next = head2;
            head2 = head2->next;
            ft = ft->next;
        }
    }
    
    if(head1==NULL){
        ft->next = head2;
    }else{
        ft->next = head1;
    }
    
    return fh;
}












































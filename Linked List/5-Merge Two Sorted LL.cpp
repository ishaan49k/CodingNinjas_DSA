/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
    if(head1==NULL){
        return head2;
    }
    
    if(head2==NULL){
        return head1;
    }
    
    Node* fh = NULL;
    Node* ft = NULL;
    
    // First set the final head of merged LL:
    if(head1->data <= head2->data){
        ft = head1;
        fh = head1;
        head1 = head1->next;
    }else{
        ft = head2;
        fh = head2;
        head2 = head2->next;
    }
    
    // Nowe we begin comparing:
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
    
    // Now if one of the LL has gotten exhasted:
    if(head1==NULL){
        ft->next = head2;
    }else{
        ft->next = head1;
    }
    
    return fh;
}












































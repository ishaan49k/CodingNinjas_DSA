Node *appendLastNToFirst(Node *head, int n){
    if(head==NULL || n==0){
        return head;
    }

    int len=0;
    Node*temp1 = head;
    while(temp1!=NULL){
        temp1=temp1->next;
        len+=1;
    }
    
    int curr = 0;
    Node* newTail = head;
    while(curr <= len-n-1){
        newTail = newTail->next;
        curr++;
    }

    Node* head2 = newTail->next;
    newTail->next = NULL;
    Node *linkingNode = head2;
    while(linkingNode->next != NULL){
        linkingNode = linkingNode->next;
    }
    
    // Connect the 2 LL:
    linkingNode->next = head;
    
    return head2;
}






Node *skipMdeleteN(Node *head, int M, int N){
    if(head==NULL || M==0){ 
        return NULL;
    }
    if(N==0){ 
        return head;
    }

    Node* currentNode = head; 
    Node* temp = NULL;
    while(currentNode!=NULL){
        int take = 0; 
        int skip = 0; 
        while(currentNode!=NULL && take<M){
            if(temp == NULL){
                temp = currentNode;
                currentNode = currentNode->next;
                take++;
            }else{
                temp->next = currentNode;
                temp = currentNode;
                currentNode = currentNode->next;
                take++;
            }
        }
        
        while(currentNode!=NULL && skip<N){
            Node* newNode = currentNode;
            currentNode = newNode->next;
            delete newNode;
            skip++;
        }
    }

    if(temp!=NULL){
        temp->next = NULL;
    }
    
    return head;
}





















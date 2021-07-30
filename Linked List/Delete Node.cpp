Node *deleteNode(Node *head, int pos){
    if(pos==0){
        Node *temp = head->next;
        delete head;
        return temp;
    }

    int counter=0;
    Node *temp = head;
    while(counter<pos-1 && temp!=NULL){
        temp = temp->next;
        counter++;
    }
    
    if(temp==NULL || temp->next==NULL){
        return head;
    }
   
    Node* del = temp->next; 
    Node* after = del->next;
    temp->next = after;
    delete del;
    return head;
}

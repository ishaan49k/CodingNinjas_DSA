Node* insertNode(Node *head, int i, int data){
    if(head==NULL){
        if(i==0){ 
            Node *newNode = new Node(data);
            head = newNode;
        }
        return head;
    }

    if(i==0){ 
        Node *newNode = new Node(data); 
        newNode->next = head;
        return newNode;
    }

    head->next = insertNode(head->next, i-1, data);
}



























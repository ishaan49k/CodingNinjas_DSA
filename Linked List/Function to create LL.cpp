// call this fxn to create a LL. to stop making any more nodes, enter -1
Node* takeInput(){
    int data;
    cin >> data;
    
    Node* head = NULL;  // this is the head of the LL we need to return
    Node* tail = NULL;  // this is the tail of LL we create. define this to make connecting new nodes at end cheaper
    
    while(data != -1){
        Node* newNode = new Node(data);
        if(head == NULL){   // if it is the first node, update the head. else connect newNode to end of LL
            head = newNode;
            tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
        
        cin >> data;
    }
    
    
    return head;
    
}

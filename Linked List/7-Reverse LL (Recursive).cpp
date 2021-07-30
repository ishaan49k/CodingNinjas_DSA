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

Node *reverseLinkedListRec(Node *head){
    //Base case:
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    // Recursive call:
    // smallAns stores the head of the reversed recursion LL
    Node* smallAns = reverseLinkedListRec(head->next);
    // Now the LL passed into recursion is reversed.
    
    // Now find the tail of the reversed LL:
    Node* tail = smallAns;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    
    // Small calculation : link the head with tail of reversed LL:
    tail->next = head;
    head->next = NULL;
    
    return smallAns;
}







































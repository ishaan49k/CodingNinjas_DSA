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

Node *reverseLinkedList(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* c = head;
    Node* n = head->next;
    Node* p = NULL;
    while(c!=NULL){
        n =c->next;
        c->next = p; // Link current node with previous node
        p = c;
        c = n;
       
    }
    return p;
}























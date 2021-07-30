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

Node *removeDuplicates(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    // initialize t1 and t2 which travel the LL:
    Node* t1 = head;
    Node *t2 = head->next;
    
    // Travel the loop and keep linking the unique elements:
    while(t2!=NULL){
        if(t1->data != t2->data){
            t1->next = t2;
            t1 = t1->next;
            t2 = t2->next;
            continue;
        }
        if(t1->data == t2->data){
            t2 = t2->next;
            continue;
        }
    }
    t1->next = t2;
    return head;
}









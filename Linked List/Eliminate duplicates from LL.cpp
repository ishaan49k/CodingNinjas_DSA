
Node *removeDuplicates(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* t1 = head;
    Node *t2 = head->next;

    while(t2!=NULL){
        if(t1->data != t2->data){
            t1->next = t2;
            t1 = t1->next;
            t2 = t2->next;
            continue;
        }
        if(t1->data == t2->data){
//             Node* temp = t2;
//             delete temp;
            t2 = t2->next;
            continue;
        }
    }
    t1->next = t2;
    return head;
}









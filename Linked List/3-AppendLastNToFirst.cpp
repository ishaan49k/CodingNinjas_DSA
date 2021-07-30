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

Node *appendLastNToFirst(Node *head, int n){
    if(head==NULL || n==0){
        return head;
    }
    // First find the lenght of the LL:
    int len=0;
    Node*temp1 = head;
    while(temp1!=NULL){
        temp1=temp1->next;
        len+=1;
    }
    
    //Now we need to find the node whose link has to be broken with its next node:
    //This node is going to be the new tail.
    int curr=1;
    Node* newTail=head;
    while(curr<len-n){
        newTail = newTail->next;
        curr++;
    }
    
    // Store the node to be the new head in head2:
    Node* head2 = newTail->next;
    // Break the connection bw 2 nodes:
    newTail->next = NULL;
    // Travel to find the tail of the broken off LL:
    Node *linkingNode = head2;
    while(linkingNode->next != NULL){
        linkingNode = linkingNode->next;
    }
    
    // Connect the 2 LL:
    linkingNode->next = head;
    
    return head2;
}






























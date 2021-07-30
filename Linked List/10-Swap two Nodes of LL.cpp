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

Node *swapNodes(Node *head, int i, int j){
    if(head==NULL || (i==j)){
        return head;
    }
    
    Node* currentNode = head;
    Node* prev = NULL;
    
    Node* firstNode = NULL;
    Node* firstNodeP = NULL;
    Node* secondNode = NULL;
    Node* secondNodeP = NULL;
    
    int pos = 0; // keeps track of the index we are on.
    
    
    
    // Travel the entire LL to assign nodes to above 4 null nodes pointers.
    // ie travel the LL to locate the nodes to be swapped by their index.
// once we arrive at index, initialize all the 4 null node pointers.
    while(currentNode!=NULL){
        if(pos==i){
            firstNodeP = prev;
            firstNode = currentNode;
        }else if(pos==j){
            secondNodeP = prev;
            secondNode = currentNode;
        }
        prev = currentNode;
        currentNode = currentNode->next;
        pos+=1;
    }
    
    if(firstNode!=NULL){
        firstNodeP->next = secondNode;
    }else{
        head = secondNode;
    }
    
    if(secondNodeP!=NULL){
        secondNodeP->next = firstNode;
    }else{
        head = firstNode;
    }
    
    Node* currentFirstNode = secondNode->next;
    secondNode->next = firstNode->next;
    firstNode->next = currentFirstNode;
    
    return head;
}

































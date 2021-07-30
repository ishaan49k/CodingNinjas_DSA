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
// RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ RDQ
Node *skipMdeleteN(Node *head, int M, int N){
    if(head==NULL || M==0){ // either LL is empty or all ele to be deleted then return NULL.
        return NULL;
    }
    if(N==0){ // ie no ele to be deleted
        return head;
    }

    Node* currentNode = head; // currentNode is used to travel the LL.
    Node* temp = NULL; // include nodes in the LL by linking temp and current node.
    
    while(currentNode!=NULL){
        int take = 0; // keeps track of how many nodes we kept
        int skip = 0; // keeps track of how many nodes we skipped.
        
        // First we run a loop to take M nodes:
        while(currentNode!=NULL && take<M){
            if(temp == NULL){
                temp = currentNode; // initialize temp.
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
//We want to delete the current node, so we first make another pointer point to the node to be deleted, move currN
// fwd and then delete the node using the pointer we made.
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





















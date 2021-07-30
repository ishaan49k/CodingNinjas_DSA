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

Node* insertNode(Node *head, int i, int data){
    // Base case: if head==NULL, no LL exists, so we cant insert node anywhere
    if(head==NULL){
        if(i==0){ // if i=0, we create a 1 node LL and return it
            Node *newNode = new Node(data);
            head = newNode;
        }
        return head;
    }
    

    // Small claculation:
    if(i==0){ // here i==0 but head!=NULL, so there is a link list whose head we need to change
        Node *newNode = new Node(data); // this is the node we need to insert
        newNode->next = head;
        return newNode;
    }
    
    // Recursive call + we link out head with the LL passed into the recursion
    head->next = insertNode(head->next, i-1, data);
}



























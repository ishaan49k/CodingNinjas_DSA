/**********************************************************

    Following are the Binary Tree Node class structure and
    the Node class structure

    template <typename T>
    class BinaryTreeNode {
        public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

    template <typename T>
    class Node {
        public:
        T data;
        Node<T> *next;
        Node(T data) {
            this->data=data;
            this->next=NULL;
        }
    };

***********************************************************/
// Final solution
// each node of LL contains data of the BInaryTreeNode
#include<queue>
#include<vector>
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root){
    if(root==NULL){
          vector<Node<int>*>output;
        return output;
    }
    
    vector<Node<int>*>output; // vector which stores heads of all LL
    
    Node<int>*head = NULL; // head = head of LL of current level
    Node<int>*tail = NULL; // tail = tail of LL of current level
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    
    while(q.size()!=0){
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        
        if(front!=NULL){
            
            // newnode is the node new node we have to add to current level LL.
               Node<int>*newnode = new Node<int>(front->data);
            
            if(head==NULL){
                head = newnode;
                tail = newnode;
            }else{
                tail->next = newnode;
                tail = newnode;
            }
            
            // Push children into queue
            if(front->left!=NULL){
                 q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
                
        }else{ // ie if front == NULL
// it means current level LL has been formed. so add its head to vector and update head and tail to NULL.
            output.push_back(head);
            head = NULL;
            tail = NULL;
            if(q.empty())
                break;
            else
                q.push(NULL);
        }
    }
    return output;
}


























































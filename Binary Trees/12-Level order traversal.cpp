/**********************************************************

    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/
// Final solution
#include<queue>

void printLevelWise(BinaryTreeNode<int> *root){
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root); // after root, level gest over, so insert NULL in the queue
    pendingNodes.push(NULL);
    
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        
        if(front == NULL){ // if front==NULL , it mena swe have reached the ends of a level
            cout << endl;
            if(pendingNodes.size() != 0){ // when we encounter NULL, it means that all nodes of next level have
                pendingNodes.push(NULL);   // been inserted in queue (check by dry running)
            }
        }else{
            cout << front->data << " ";
            if(front->left != NULL){
                pendingNodes.push(front->left);
            }
            
            if(front->right != NULL){
                pendingNodes.push(front->right);
            }
        }
    }
}








































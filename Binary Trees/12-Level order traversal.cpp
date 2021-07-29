#include<queue>

void printLevelWise(BinaryTreeNode<int> *root){
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root); 
    pendingNodes.push(NULL);
    
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        
        if(front == NULL){ 
            cout << endl;
            if(pendingNodes.size() != 0){
                pendingNodes.push(NULL);
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

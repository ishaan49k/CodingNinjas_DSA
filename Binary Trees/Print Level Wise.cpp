#include<queue>
void printLevelWise(BinaryTreeNode<int> *root){
    if(root==NULL){
        return ;
    }
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* frontNode = pendingNodes.front();
        pendingNodes.pop();

        cout << frontNode->data << ":";
        cout << "L:";
        if(frontNode->left != NULL){
            pendingNodes.push(frontNode->left);
            cout << frontNode->left->data << ",";
        }else{
            cout << "-1" << ",";
        }
        
        cout << "R:";
        if(frontNode->right != NULL){
            pendingNodes.push(frontNode->right);
            cout << frontNode->right->data << endl;
        }else{
            cout << "-1" << endl;
        }

    }
}


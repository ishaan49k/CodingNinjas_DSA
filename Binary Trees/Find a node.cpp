bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    if(root==NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    
    // call recursion to check on left and right node.
    if(isNodePresent(root->left,x)){
        return true;
    }
    if(isNodePresent(root->right,x)){
        return true;
    }
    
    return false;
    
}






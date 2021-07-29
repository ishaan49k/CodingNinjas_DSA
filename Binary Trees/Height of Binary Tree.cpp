int height(BinaryTreeNode<int>* root) {
    if(root==NULL){
        return 0;
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return 1+ max(leftHeight, rightHeight);
    
}




















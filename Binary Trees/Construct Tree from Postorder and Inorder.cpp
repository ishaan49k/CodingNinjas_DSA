

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postorder[postLength-1]);
    
    if(postLength == 1)
        return root;
    
    if(postLength == 0)
        return NULL;
    
    int i = 0;
    while(inorder[i] != postorder[postLength - 1]){
        i++;
    }
    
    int left_size = i;
    int right_size = inLength -i - 1;
    
    BinaryTreeNode<int> *leftSubtree = buildTree(postorder, left_size, inorder, left_size);
    BinaryTreeNode<int> *rightSubtree = buildTree(postorder + left_size, right_size, inorder + 1 + left_size, right_size);
    
    root -> left = leftSubtree;
    root -> right = rightSubtree;
    
    return root;
}



BinaryTreeNode<int>* buildTreeHelper(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd){

    if(preStart > preEnd || inStart > inEnd){
        return NULL;
    }
    
    int rootValue = preorder[preStart];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootValue);
k.
    int k=0;
    for(int i=inStart; i<= inEnd; i++){
        if(rootValue == inorder[i]){
            k = i;
            break;
        }
    }

    int leftInStart = inStart;  // obvious
    int leftInEnd = k-1;      
    int leftPreStart = preStart + 1;  // obvious
    int leftPreEnd = leftInEnd - leftInStart + leftPreStart;
    int rightPreStart = leftPreEnd + 1;
    int rightPreEnd = preEnd;  // obvious
    int rightInStart = k+1;    // obvious
    int rightInEnd = inEnd;  //obvious

    root->left = buildTreeHelper(preorder, leftPreStart, leftPreEnd, inorder, leftInStart, leftInEnd);
    root->right = buildTreeHelper(preorder,rightPreStart, rightPreEnd, inorder, rightInStart, rightInEnd);
    
    return root;
    
}



BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength){
    int preStart = 0;
    int preEnd = preLength -1;
    int inStart = 0;
    int inEnd = inLength -1;
    
    return buildTreeHelper(preorder, preStart, preEnd, inorder, inStart, inEnd);
    
    
}





















































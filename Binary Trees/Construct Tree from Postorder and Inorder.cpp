/***********************************************************
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
// Final code

BinaryTreeNode<int>* buildTreeHelper(int* postorder, int postStart, int postEnd, int* inorder, int inStart, int inEnd){
	if(postStart > postEnd || inStart > inEnd){
        return NULL;
    }    
    
    int rootData = postorder[postEnd];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    
    // find the index of root in inorder
    int k = 0;  // this stores the index of root in inorder
    for(int i=inStart; i<=inEnd; i++){
        if(inorder[i] == rootData){
            k = i;
            break;
        }
    }
    
    // call recursion to build the left and right subtrees and link it to the root
    root->left = buildTreeHelper(postorder, postStart, postStart+k-inStart-1, inorder, inStart, k-1);
    root->right = buildTreeHelper(postorder, postStart+k-inStart, postEnd-1, inorder, k+1, inEnd);
    
    return root;
    
    
    
}




BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength){
    int postStart = 0;
    int postEnd = postLength - 1;
    int inStart = 0;
    int inEnd = inLength - 1;
    
    
    // now we have the inorder, inStart, inEnd, postorder, postStart, postEnd of the tree we need to build
    return buildTreeHelper(postorder, postStart, postEnd, inorder, inStart, inEnd);
}




------------------------------------------------------------------------------------------------------------------------------------------------------------








// another code that works:

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

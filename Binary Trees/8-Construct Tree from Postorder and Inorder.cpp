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
// write your own code. it will be easy if youve done

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postorder[postLength-1]);
    
    if(postLength == 1)    // base case when only root is present and no left or right node
        return root;
    
    if(postLength == 0)    //if one of both right or left is present check for 2, 1 2, 1 2;;;dry run it
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

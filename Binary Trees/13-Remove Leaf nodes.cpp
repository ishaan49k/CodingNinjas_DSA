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
// Finall solution
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root){
    // Base case:
    if(root == NULL){
        return NULL;
    }
    
    // Small calculation: check if root is a leaf node:
    if(root->left == NULL && root->right == NULL){
        return NULL;
    }
    
    // Recursive call:
    // call recursion on left and right subtree and connect the updates roots with root
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    
    
}





























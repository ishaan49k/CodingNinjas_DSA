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
// Final solution:
void postOrder(BinaryTreeNode<int> *root) {
    //Base case:
    if (root == NULL)
        return;
  
    // first recur on left subtree
    postOrder(root->left);
  
    // then recur on right subtree
    postOrder(root->right);
  
    // now deal with the node
    cout << root->data << " ";
}

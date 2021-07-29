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
// final solution

void preOrder(BinaryTreeNode<int> *root){
    //Base case:
    if(root==NULL){
        return;
    }
    
    //Print the root node first
    cout << root->data << " ";
    
    // Print left child followed by right
    preOrder(root->left);
    preOrder(root->right);
    
}





























































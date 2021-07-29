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
//Final solution:
int getSum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int leftAns = getSum(root->left);
    int rightAns = getSum(root->right);
    
    return leftAns + rightAns + root->data;

}

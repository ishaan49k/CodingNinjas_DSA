/**********************************************************

    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
        public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/
// Final code

// fxn returns the sum of the tree on which it is called
int replaceWithLargerNodesSumHelper(BinaryTreeNode<int> *root, int sum){
    // Base case
    if(root == NULL){
        return sum;
    }
    
    // call on right
    sum = replaceWithLargerNodesSumHelper(root->right, sum);
    
    // small calculation on root
    sum += root->data;
    root->data = sum;
    
    // recursion on left
    sum = replaceWithLargerNodesSumHelper(root->left, sum);
    
    return sum;
}




void replaceWithLargerNodesSum(BinaryTreeNode<int> *root){
    int sum = 0;
    replaceWithLargerNodesSumHelper(root, sum);
    
}







































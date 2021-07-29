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

// create class:
class balanceReturnType{
    public:
    int height;
    int balanced;
};

// Create a helper function:
balanceReturnType* isBalancedHelper(BinaryTreeNode<int> *root){
    //base case:
    if(root == NULL){
        balanceReturnType* ans = new balanceReturnType();
        ans->height = 0;
        ans->balanced = true;
        return ans;
    }
    
    // Recursive call:
    balanceReturnType* leftAns = isBalancedHelper(root->left);
    balanceReturnType* rightAns = isBalancedHelper(root->right);
    
    // Small calculation:
    bool temp; // stores if the current node is balanced or not:
    if(!(leftAns->balanced) || !(rightAns->balanced) || (abs(leftAns->height - rightAns->height)>1)){
        temp = false;
    }else{
        temp = true;
    }
    
    balanceReturnType* output = new balanceReturnType();
    output->height = max(leftAns->height, rightAns->height) + 1;
    output->balanced = temp;
    return output;
    
}



bool isBalanced(BinaryTreeNode<int> *root){
    if(root == NULL){
        return true;
    }
    
    return isBalancedHelper(root)->balanced;
}
















































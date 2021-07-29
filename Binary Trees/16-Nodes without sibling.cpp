/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void printNodesWithoutSibling(BinaryTreeNode<int> *root){
    // Base case
    if(root==NULL)
        return;
    
    // Small calculation
    if(root->left==NULL&&root->right!=NULL)
        cout<<root->right->data<<" ";
    if(root->left!=NULL&&root->right==NULL)
        cout<<root->left->data<<" ";
    
    // Recursive call
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}

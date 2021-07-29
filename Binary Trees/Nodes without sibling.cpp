
void printNodesWithoutSibling(BinaryTreeNode<int> *root){

    if(root==NULL)
        return;
    

    if(root->left==NULL&&root->right!=NULL)
        cout<<root->right->data<<" ";
    if(root->left!=NULL&&root->right==NULL)
        cout<<root->left->data<<" ";
    

    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}

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
// Final code:

void insertDuplicateNode(BinaryTreeNode<int> *root){
    // Base case.
    if(root == NULL){
        return;
    }
    
    // Small calculation on the root node:
    BinaryTreeNode<int> *duplicateNode = new BinaryTreeNode<int>(root->data); // create the duplicate node.
    BinaryTreeNode<int> *temp = root->left; // this pointer stores the address of the left subtree.
    // make connection of the root node with its duplicate:
    root->left = duplicateNode;
    duplicateNode->left = temp;
    
    // recursive call:
    insertDuplicateNode(duplicateNode->left);  // we need to pass left of the duplicateNode
    insertDuplicateNode(root->right);
    
}


-------------------------------------------------------------------------------------------------------------
    
// Even this code work. Here is called recursion on left and right subtrees first and then handled the root node

void insertDuplicateNode(BinaryTreeNode<int> *root){
    // Base case
    if(root == NULL){
        return;
    }
    
    // call recursion on left and right subtrees
    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);
    
    // work on the root node
    BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int>* temp = root->left;  // temp stores the address of theleft subtree
    
    root->left = newNode;
    newNode->left = temp;
    
    
    
}






















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

void depth(BinaryTreeNode<int> *root, int k) {
    if(root == NULL) {
        return;
    }
    
    
    if(k == 0) {
        cout << root -> data << endl;
        return;
    }
    
    
    depth(root -> left, k - 1);
    depth(root -> right, k - 1);
    
    
    
}




// taget node has data == ele
// returns the distance bw the root node and target node
int nodesAtDistanceKHelper(BinaryTreeNode<int> *root, int ele, int k) {
    if(root == NULL){
        return -1;
    }
    
    
    // we are at the ele node. print all nodes at depth k fron it
    if(root->data == ele){
        depth(root, k);
        return 0;
    }
    
    
    
    // if not at taget node, call recursion on left subtree
    int leftD = nodesAtDistanceKHelper(root->left, ele, k);
    if (leftD != -1){  // if not -1, it means we have found the target node in left subtree
        if(leftD+1 == k){
            cout << root->data << endl;
        }else{
            depth(root->right, k-leftD - 2);
        }
        
        return 1 + leftD;
    }
    
    
    
    int rightD = nodesAtDistanceKHelper(root->right, ele, k);
    if(rightD != -1){
        if(rightD+1 == k){
            cout << root -> data << endl;
        }else{
            depth(root->left, k - rightD - 2);
        }
         
        return 1 + rightD;
    }
    
    
    return -1;
    
    
}










// prints all nodes at a distance k fron node in given binary tree
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    nodesAtDistanceKHelper(root, node, k);

}


















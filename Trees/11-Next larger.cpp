/************************************************************
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };
************************************************************/

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x){
    if(root==NULL){
        return NULL;
    }
    
    // ans stores the final node adress we have to return.
    TreeNode<int>* ans = NULL;
    
    if(root->data > x){
        ans = root;
    }
    
    // Call recursion on all children of root node:
    for(int i=0; i<root->children.size(); i++){
        TreeNode<int>* childAns = getNextLargerElement(root->children[i], x);
        if(ans == NULL){
            ans = childAns;
        }else{ // ie there is data in nextLargestNode: compare the data of temp with it
            if(childAns!=NULL && childAns->data<ans->data){
                ans = childAns;
            }
        }
    }
    
    return ans;
    
}


































































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

bool isPresent(TreeNode<int>* root, int x){
    if(root==NULL){
        return false;
    }
    
    // Check if x in in root node:
    if(root->data==x){
        return true;
    }
    
    // check if x in there in children of root node:
    for(int i=0; i<root->children.size(); i++){
        bool ans = isPresent(root->children[i], x);
        if(ans){
            return ans;
        }
    }
    
    return false;
}









































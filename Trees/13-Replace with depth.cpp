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
void replaceWithDepthValueHelper(TreeNode<int>* root, int depth){
    // handle root node:
    root->data = depth;
    
    // Call recursion of children of root node:
    for(int i=0; i<root->children.size(); i++){
        replaceWithDepthValueHelper(root->children[i], depth+1);
    }
}


void replaceWithDepthValue(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    
    replaceWithDepthValueHelper(root, 0);
}












































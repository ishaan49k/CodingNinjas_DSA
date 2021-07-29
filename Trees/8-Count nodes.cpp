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

int getLargeNodeCount(TreeNode<int>* root, int x){
    int count = 0;
    
    if(root->data > x){
        count+=1;
    }
    
    for(int i=0; i<root->children.size(); i++){
        int child_ans = getLargeNodeCount(root->children[i],x); // child_ans stores the no of nodes in subtree more than x
        count += child_ans;
    }
    
    return count;
}
















































bool isPresent(TreeNode<int>* root, int x){
    if(root==NULL){
        return false;
    }

    if(root->data==x){
        return true;
    }

    for(int i=0; i<root->children.size(); i++){
        bool ans = isPresent(root->children[i], x);
        if(ans){
            return ans;
        }
    }
    
    return false;
}

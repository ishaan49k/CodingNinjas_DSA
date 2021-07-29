

int getLeafNodeCount(TreeNode<int>* root) {
    int ans = 0;
    if(root->children.empty()){
    return 1;
    }
    
   
    for(int i=0; i<root->children.size(); i++){
        ans+= getLeafNodeCount(root->children[i]);
    }
    
    return ans;
}

       
    // solve this by creating an array using the tree by travelling in inorder
    // if the tree is BST, we will get a sorted array. use a for loop to check this


    // takes in a tree and populates vector v with inorder traversal
    void inorder(TreeNode* root, vector<int> &v){
        if(root == NULL){
            return;
        }
        
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
        
    }
    
    
  
    
    bool isValidBST(TreeNode* root){
        if(root == NULL){
            return true;
        }
        
        
        vector<int> v;
        inorder(root, v);
        
        bool isBST = true;
        int mx = v[0];
        for(int i=1; i<v.size(); i++){
            if(v[i] <= mx){
                isBST = false;
                break;
            }else{
                mx = v[i];
            }
        }
        
        return isBST;
        
        
    }
    

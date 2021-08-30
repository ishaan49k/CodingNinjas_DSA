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
// Final code
// find out how this code works
#include <vector>

// this function prints all the paths 
void rootToLeafPathsSumToKHelper(BinaryTreeNode<int> *root, vector<int> &path, int k){
    // base case
    if(root == NULL){
        return;
    }
    
    // work on root node
    k -= root->data;
    path.push_back(root->data);  // add curr node at the end of vector
    
    // we have reached a leaf node. if k==0, then we have found a valid path we can print
    if(root->left == NULL && root->right == NULL){
        if(k == 0){
            for(int i=0; i<path.size(); i++){
                cout << path[i] << " ";
            }
            cout << endl;
        }
        path.pop_back();   // by pop back, we remove latest added node from back of vector. and we backtrack to its parent node
        return;
    }
    
    // recursive call
    rootToLeafPathsSumToKHelper(root->left, path, k);
    rootToLeafPathsSumToKHelper(root->right, path, k);
    
    path.pop_back();
}



void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k){
    vector<int> path;
    rootToLeafPathsSumToKHelper(root, path, k);
    
}




-----------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  // This code works too
  
  // this function prints all the paths 
  
void helper(BinaryTreeNode<int> *root, int k, vector<int> path){
    
    if(root == NULL){
        return;
    }
    
    // check if current node is a leaf node
    if(root -> left == NULL && root -> right == NULL){
        if((k - root->data) == 0){   // if the node is a valid path, then print path and then current node data
            for(int i=0; i<path.size(); i++){
                cout << path[i] << " ";
            }
   
            cout << root->data << endl;
        }
        
        return;
    }
    
    
    
	// push root data into path and then call recursion on left and right subtrees
    path.push_back(root -> data);
    helper(root -> left, k - root -> data, path);
    helper(root -> right, k - root -> data, path);
    
    
}








void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    vector<int> path;
    helper(root, k, path);
}










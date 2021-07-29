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
#include<climits>

template <typename T>
class MaxNodePair{
    public:
    TreeNode<T>* node; // tree node pointer called node
    int sum; // this is the sum of that node.
};

// Define the helper function:
// return type of this function is an object of MaxNodePair class
MaxNodePair<int>* maxSumNodeHelper(TreeNode<int>* root){
    if(root==NULL){
        MaxNodePair<int>* pair = new MaxNodePair<int>();
        pair->node = NULL;
        pair->sum = INT_MIN;
        return pair;
    }
    
    // sum holds the sum of the root node and its children.
    int sum = root->data;
    
    // call for loop to find the total sum of the root node.
    for(int i=0; i<root->children.size(); i++){
        sum+=root->children[i]->data;
    }
    
    // the answer node is ans. assume initially that the answer is the root node.
    MaxNodePair<int>* ans = new MaxNodePair<int>();
    ans->sum = sum;
    ans->node = root;
    
    // call recursion on all the children of the root node.
    for(int i=0; i<root->children.size(); i++){
        MaxNodePair<int>* childAns = maxSumNodeHelper(root->children[i]);//childAns stores the max node of subtree
        
        // Compare the sum of childAns and the root node
        if(childAns->sum > ans->sum){
            ans = childAns;
        }
    }
    
    return ans;
}



TreeNode<int>* maxSumNode(TreeNode<int>* root){
    // pass the root node into helper function
    return maxSumNodeHelper(root)->node;
}





















































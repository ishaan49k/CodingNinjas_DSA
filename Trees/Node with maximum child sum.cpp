
#include<climits>

template <typename T>
class MaxNodePair{
    public:
    TreeNode<T>* node; 
    int sum;
};

MaxNodePair<int>* maxSumNodeHelper(TreeNode<int>* root){
    if(root==NULL){
        MaxNodePair<int>* pair = new MaxNodePair<int>();
        pair->node = NULL;
        pair->sum = INT_MIN;
        return pair;
    }
    int sum = root->data;
    for(int i=0; i<root->children.size(); i++){
        sum+=root->children[i]->data;
    }
    MaxNodePair<int>* ans = new MaxNodePair<int>();
    ans->sum = sum;
    ans->node = root;
    for(int i=0; i<root->children.size(); i++){
        MaxNodePair<int>* childAns = maxSumNodeHelper(root->children[i]);
        if(childAns->sum > ans->sum){
            ans = childAns;
        }
    }
    
    return ans;
}



TreeNode<int>* maxSumNode(TreeNode<int>* root){
    return maxSumNodeHelper(root)->node;
}


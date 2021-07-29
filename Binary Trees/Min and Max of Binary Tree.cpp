
#include<climits>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root){

    if(root == NULL){
        pair<int, int> p(INT_MAX, INT_MIN);
        return p;
    }

    pair<int, int> leftAns = getMinAndMax(root->left);
    pair<int, int> rightAns = getMinAndMax(root->right);
    
    int leftMin = leftAns.first;
    int leftMax = leftAns.second;
    int rightMin = rightAns.first;
    int rightMax = rightAns.second;

    pair<int, int> finalAns;
    finalAns.first = min(root->data, min(leftMin, rightMin));
    finalAns.second = max(root->data, max(leftMax, rightMax));
    
    return finalAns;
    
}
















































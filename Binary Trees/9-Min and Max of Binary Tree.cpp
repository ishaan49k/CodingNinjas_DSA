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

/*
    The first value of the pair must be the minimum value in the tree and
    the second value of the pair must be the maximum value in the tree
*/

//Final solution.
#include<climits>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root){
    //Base case:
// intialize the min to be INT_MAX and min to be INT_MAX
    if(root == NULL){
        pair<int, int> p(INT_MAX, INT_MIN);
        return p;
    }
    
    // Recursive call: get the left min, max and righ min, max.
    // then to find total max, compare left max, right max and value in node.
    pair<int, int> leftAns = getMinAndMax(root->left);
    pair<int, int> rightAns = getMinAndMax(root->right);
    
    int leftMin = leftAns.first;
    int leftMax = leftAns.second;
    int rightMin = rightAns.first;
    int rightMax = rightAns.second;
    
    // Small calculation:
    pair<int, int> finalAns;
    finalAns.first = min(root->data, min(leftMin, rightMin));
    finalAns.second = max(root->data, max(leftMax, rightMax));
    
    return finalAns;
    
}
















































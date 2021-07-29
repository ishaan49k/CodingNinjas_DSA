/***********************************************************
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
//Final solution

BinaryTreeNode<int>* buildTreeHelper(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd){
    
//Base case: when the input array is empty.
// since the size o fboth arrays is same, we could have done only preStart > preEnd
    if(preStart > preEnd || inStart > inEnd){
        return NULL;
    }
    
    int rootValue = preorder[preStart];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootValue);
    
    // Find root index in inorder array and store it in k.
    int k=0;
    for(int i=inStart; i<= inEnd; i++){
        if(rootValue == inorder[i]){
            k = i;
            break;
        }
    }
    
    // Also k = length of left subtree.
    // we need these 8 values to be able to call recursion.
    
// Always define the obvious ones first. here if we define line leftPreEnd first we get an error.
    int leftInStart = inStart;  // obvious
    int leftInEnd = k-1;        // ie root index - 1.
    int leftPreStart = preStart + 1;  // obvious
    int leftPreEnd = leftInEnd - leftInStart + leftPreStart;
    int rightPreStart = leftPreEnd + 1;
    int rightPreEnd = preEnd;  // obvious
    int rightInStart = k+1;    // obvious
    int rightInEnd = inEnd;  //obvious
    
    // Call recursion to construct left and right subtree and link both with node.
    root->left = buildTreeHelper(preorder, leftPreStart, leftPreEnd, inorder, leftInStart, leftInEnd);
    root->right = buildTreeHelper(preorder,rightPreStart, rightPreEnd, inorder, rightInStart, rightInEnd);
    
    return root;
    
}



BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength){
    int preStart = 0;
    int preEnd = preLength -1;
    int inStart = 0;
    int inEnd = inLength -1;
    
    return buildTreeHelper(preorder, preStart, preEnd, inorder, inStart, inEnd);
    
    
}



/*
->To find the root value, we dont do preorder[0] cuz we need to work on a generalized array. hence [preStart].

->To find inorder end: first find the location of root in inorder array. we scan the array from inStart to inEnd.

->To find left pre order end, equate the length of left preorder and left inorder:
leftpreend - left prestart = leftinend - lefttinstart:

->To find right preorder = leftpreend + 1.



*/

















































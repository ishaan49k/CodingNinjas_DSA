/**********************************************************

    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
        public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };
    
***********************************************************/
// Final solution

#include <stack>

int countNodes(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    
    return countNodes(root->left) + countNodes(root->right) + 1;
}




void printNodesSumToS(BinaryTreeNode<int> *root, int s){
    // base case
    if(root == NULL){
        return;
    }
    
    int totalNodes = countNodes(root);
    int count = 0;
    
    // create 2 stacks which store adresses of nodes and not their data
    stack<BinaryTreeNode<int>*> inorder;
    stack<BinaryTreeNode<int>*> revInorder;
    
    // fill the inoder stack
    BinaryTreeNode<int>* currentNode = root;
    while(currentNode != NULL){
        inorder.push(currentNode);
        currentNode = currentNode->left;
    }
    
    // fill revInorder stack
    currentNode = root;
    while(currentNode != NULL){
        revInorder.push(currentNode);
        currentNode = currentNode->right;
    }
    
    // keep comparing elemets of 2 stacks
    while(count < totalNodes - 1){
        BinaryTreeNode<int>* inorderTop = inorder.top();
        BinaryTreeNode<int>* revInorderTop = revInorder.top();
        
        // compare both tops:
        if(inorderTop->data + revInorderTop->data == s){
            cout << inorderTop->data << " " << revInorderTop->data << endl;
            
            // pop inorder top and insert elements in it such that just larger than it is at top of stack
            BinaryTreeNode<int>* top = inorderTop;
            inorder.pop();
            count++;
            if(top->right != NULL){
                top = top ->right;
                while(top != NULL){
                    inorder.push(top);
                    top = top->left;
                }
            }
            
            // pop revInorder top and insert elements in it such that just smaller than it is at top of stack
            top = revInorder.top();
            revInorder.pop();
            count++;
            if(top->left != NULL){
                top = top->left;
                while(top != NULL){
                    revInorder.push(top);
                    top = top->right;
                }
            }
        
            // sum of both tops > s: go to next largest ele in revInorder
        }else if(inorderTop->data + revInorderTop->data > s){
            BinaryTreeNode<int>* top = revInorderTop;
            revInorder.pop();
            count++;
            if(top->left != NULL){
                top = top->left;
                while(top != NULL){
                    revInorder.push(top);
                    top = top->right;
                }
            }
            
             // sum of both tops < s: go to next smaller ele in inorder
        }else{
            BinaryTreeNode<int>* top = inorderTop;
            inorder.pop();
            count++;
            if(top->right != NULL){
                top = top->right;
                while(top != NULL){
                    inorder.push(top);
                    top = top->left;
                }
            }
        }
        
    }
    
    
}




























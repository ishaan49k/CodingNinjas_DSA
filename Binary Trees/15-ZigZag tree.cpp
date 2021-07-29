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

// Final solution

#include<stack>
void zigZagOrder(BinaryTreeNode<int> *root) {
    
    stack<BinaryTreeNode<int>*>srl; // R->L
    stack<BinaryTreeNode<int>*>slr; // L->R
    
    srl.push(root);
    
    while (srl.size()!=0 || slr.size()!=0){
        
        // start working on srl cuz we've pushed root into it
        while(srl.size() != 0){
            BinaryTreeNode<int>* curr = srl.top();
            cout<<curr->data<<" ";
            srl.pop();
            
            // put children of curr in the other stack
            if (curr->left != NULL){
                slr.push(curr->left);
            }
            if (curr->right != NULL){
                slr.push(curr->right);
            }
            
            // if the stack becomes empty, move to next line
            if(srl.size() == 0)
                cout<<endl;
        }
        
        // if srl is empty, then work on slr
        while(slr.size() != 0){
            BinaryTreeNode<int>* curr = slr.top();
            cout<<curr->data<<" ";
            slr.pop();
            
            // push children of curr into srl
            if (curr->right != NULL){
                srl.push(curr->right);
            }
            if (curr->left != NULL){
                srl.push(curr->left);
            }
                
            if(slr.size()==0)
                cout<<endl;
        }
        
     }
}













































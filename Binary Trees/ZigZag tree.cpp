
#include<stack>
void zigZagOrder(BinaryTreeNode<int> *root) {
    
    stack<BinaryTreeNode<int>*>srl;
    stack<BinaryTreeNode<int>*>slr;
    
    srl.push(root);
    
    while (srl.size()!=0 || slr.size()!=0){

        while(srl.size() != 0){
            BinaryTreeNode<int>* curr = srl.top();
            cout<<curr->data<<" ";
            srl.pop();

            if (curr->left != NULL){
                slr.push(curr->left);
            }
            if (curr->right != NULL){
                slr.push(curr->right);
            }

            if(srl.size() == 0)
                cout<<endl;
        }

        while(slr.size() != 0){
            BinaryTreeNode<int>* curr = slr.top();
            cout<<curr->data<<" ";
            slr.pop();

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













































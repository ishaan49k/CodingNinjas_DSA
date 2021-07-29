
#include<queue>
#include<vector>
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root){
    if(root==NULL){
          vector<Node<int>*>output;
        return output;
    }
    
    vector<Node<int>*>output;
    
    Node<int>*head = NULL; 
    Node<int>*tail = NULL; 
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    
    while(q.size()!=0){
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        
        if(front!=NULL){

               Node<int>*newnode = new Node<int>(front->data);
            
            if(head==NULL){
                head = newnode;
                tail = newnode;
            }else{
                tail->next = newnode;
                tail = newnode;
            }

            if(front->left!=NULL){
                 q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
                
        }else{
            output.push_back(head);
            head = NULL;
            tail = NULL;
            if(q.empty())
                break;
            else
                q.push(NULL);
        }
    }
    return output;
}


























































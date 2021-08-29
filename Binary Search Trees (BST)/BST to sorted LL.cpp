/**********************************************************

	Following are the Binary Tree Node class structure and the 
	Node class structure

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

	template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

***********************************************************/
// Final code:

class LinkedList{
    public:
    Node<int>* head;
    Node<int>* tail;
    
    // Constructor:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
};

LinkedList constructLinkedListHelper(BinaryTreeNode<int>* root){    
    // Base case:
    if(root == NULL){
        LinkedList combinedLL;
        return combinedLL;
    }
    
    LinkedList leftLL = constructLinkedListHelper(root->left);
    LinkedList rightLL = constructLinkedListHelper(root->right);
    Node<int>* rootNode = new Node<int>(root->data);
    // we need to connect the above 3 things:
    
    if(leftLL.head != NULL){ // ie, there is a left linked list.
        leftLL.tail->next = rootNode;
    }
    rootNode->next = rightLL.head;
    
    LinkedList combinedLL;
    // Put head and tail of final LL in the combinedLL object and return it:
    if(leftLL.head != NULL){
        combinedLL.head = leftLL.head;
    }else{ // ie there is no LL of left. ie all elements of BST were on the right
        combinedLL.head = rootNode;
    }
    
    if(rightLL.tail != NULL){
        combinedLL.tail = rightLL.tail;
    }else{ //ie, there are no elemnts on the right of BST.
        combinedLL.tail = rootNode;
    }
    
    return combinedLL;
    
}


Node<int>* constructLinkedList(BinaryTreeNode<int>* root){
    return constructLinkedListHelper(root).head;
    
}






---------------------------------------------------------------------------------------------------------------

// Even this code works. 


pair<Node<int>*, Node<int>*> constructLinkedListHelper(BinaryTreeNode<int>* root){
    
    if(root == NULL){
        pair<Node<int>*, Node<int>*> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }
    
    // there is a root node. so create a LL node containining its data
    Node<int>* rootNode = new Node<int>(root->data);
    
    // call recursion on the left subtree
    pair<Node<int>*, Node<int>*> leftLL = constructLinkedListHelper(root->left);
    
    if(leftLL.first != NULL){  // ie, there were nodes present in the left subtree
        leftLL.second->next = rootNode;
    }
    
    // call recursion on right subtree
    pair<Node<int>*, Node<int>*> rightLL = constructLinkedListHelper(root->right);
    
    // connect the rootNode with the right LL's head
    rootNode->next = rightLL.first;
    
    // now our LL is ready. we need to create a pair object and return it
    pair<Node<int>*, Node<int>*> finalLL;
    
    if(leftLL.first != NULL){
        finalLL.first = leftLL.first;
    }else{
        finalLL.first = rootNode;
    }    
    
    if(rightLL.second != NULL){
        finalLL.second = rightLL.second;
    }else{
        finalLL.second = rootNode;
    }
    
    
    return finalLL;
    
}




Node<int>* constructLinkedList(BinaryTreeNode<int>* root){
    return constructLinkedListHelper(root).first;
}







































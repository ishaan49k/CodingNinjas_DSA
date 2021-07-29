

class Stack {
    Node *head;
    int size;
    public:
        Stack() {
            head = NULL;
            size = 0;
        }
    int getSize() {
    return size;
    }
    bool isEmpty() {
    return size == 0;
    }
    void push(int element) {
    Node *newnode = new Node(element);
    if (head == NULL) {
    head = newnode;
    } else {
    newnode->next = head;
    head = newnode;
    }
    size++;
    }
    int pop() {
    if (head == NULL) {
    return -1;
    }
    int ans = head->data;
    Node *temp = head;
    head = head->next;
    delete temp;
    size--;
    return ans;
    }
    int top() {
    if (head == NULL) {
    return -1;
    }
    return head->data;
    }
};


// using array
    Class Stack{
        int *arr;
        int size;
        int top;
    public:
        Stack(int s){
            size = s;
            top = -1;
            arr = new int[s];
        }
        bool isEmpty(){
            return top == -1;
        }
        bool isFull(){
            return top == size-1;
        }
        void push(int value){
            if(isFull()){
                cout << "overflow" << endl;
                return;
            }
            top++;
            arr[top] = value;
        }
        void pop(){
            if(isEmpty()) {
                cout << "uderflow" << endl;
                return;
            }
            else{
                top = top - 1;
            }
        }
        int peek(){
            if(isEmpty()) {
                cout << "Stack is Empty" << endl;
                return -1;
            }
            return arr[top];
        }
        void stackSize(){
            return top+1;
        }
    }

// using linked list
    Class Node{
    public:
        int data;
        Node* next;

        Node(int value){
            data = value;
            next = NULL;
        }
    }
    Class Stack{
        Node *top;
        int size;
    public:
        Stack(){
            top = NULL;
            size = 0;
        }
        bool isEmpty(){
            return top == NULL;
        }
        void push(int val){
            Node* temp = top;
            top = new Node(val);
            top->next = temp;
            size++;
            
        }
        void pop(){
            if(isEmpty())
                return;

            Node* temp = top;
            top = top->next;
            delete temp; 
        }
        int peek(){
            if(isEmpty()) return -1;
            return top->data;
        }
    }
// using 2 queue

// implement 2 stack in an array

// using deque | STL e stack dequeue diye implemeted

// using array
    Class Queue{
        int *arr;
        int front, rear;
        int size;

    public:
        Queue(int n){
            arr = new int[n];
            front = -1, rear = -1;
            size = n;
        }

        bool isEmpty(){
            return front == -1;
        }

        bool isFull(){
            return rear == n-1;
        }
        void push(int x){
            if(isEmpty()) {
                front = rear = 0;
                arr[front] = x;
            }
            else if(isFull()){
                cout << "Queue Overflow";
                return;
            }
            else{
                rear+=1;
                arr[rear] = x;
            }
        }
        void pop(){
            if(isEmpty()){
                cout << "Underflow" << endl;
                return;
            }
            else{
                if(front == rear)
                    front = rear = -1;
                else
                    front += 1;
            }
        }
        int front(){
            if(isEmpty()){
                cout << "Queue is Empty" << endl;
                return -1;
            }
            return arr[front];
        }
    }

// circular queue using array
    bool isFull(){
        return (rear+1)%size == front;
    }
    void push(int x){
        if(isEmpty()){
            front = rear = 0;
            arr[rear] = x;
        }
        else{ 
            if(isFull()){
                cout << "Overflow" << endl;
                return;
            }else{
                rear = (rear + 1)%size;
                arr[rear] = x;
            }
        }
    }
    void pop(){
        if(isEmpty()){
            cout << "Underflow"<< endl;
            return;
        }
        else{
            if(front == rear) front = rear = -1;
            else front = (front+1) % size;
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
    Class Queue{
        Node* front;
        Node* rear;
    public:
        Queue(){
            front = rear = NULL;
        }
        bool isEmpty(){
            return front == NULL;
        }
        void push(int x){
            if(isEmpty()){
                front = new Node(x);
                rear = front;
                return;
            }else{
                rear->next = new Node(x);
                rear = rear->next;
            }
        }
        void pop(){
            if(isEmpty()){
                cout << "Underflow";
                return;
            }else{
                Node* temp = front;
                front = front->next;
                delete temp;
            }
        }
        int front(){
            if(isEmpty()){
                cout << "empty" << endl;
                return -1;
            }else{
                return front->data;
            }
        }
    }

// using 2 stack
    Class Queue{
        stack<int> st1; // for push
        stack<int> st2; // for pop
    }

// using deque

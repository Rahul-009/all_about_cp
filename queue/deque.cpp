// using linked list
    Class Node{
    public:
        int data;
        Node* next, prev;

        Node(int value){
            data = value;
            next = NULL;
            prev = NULL;
        }
    }

    Class Deque{
        Node *front, *rear;
    public:
        Dequeue(){
            front = rear = NULL;
        }   
        void push_front(int x){
            if(front == NULL){
                front = rear = new Node(x);
                return
            }else{
                Node *temp = new Node(x);
                temp->next = front;
                front->pre = temp;
                return;
            }
        }
        void push_back(int x){
            if(front == NULL){
                front = rear = new Node(x);
            }else{
                Node *temp = new Node(x);
                rear->next = temp;
                temp->prev = rear;
                rear = temp;
                return;
            }
        }
        void pop_front(){
            if(front == NULL){
                cout << "Underflow" << endl;
                return;
            }else{
                Node *temp = front;
                front = front->next;
                delete temp;
                if(front) front->prev = NULL;
                else rear = NULL;
            }
        }
        void pop_back(){
            if(rear == NULL){
                return;
            }else{
                Node *temp = rear;
                rear = rear->prev;
                delete temp;
                if(rear) rear->next = NULL;
                else front = NULL;
            }
        }
        int front(){
            if(front == NULL)
                return -1
            else
                return front->data;
        }
        int back(){
            if(rear == NULL) return -1;
            else return rear->data;
        }
    }

// using array
    Class Dequeue{
        int front, rear, size;
        int *arr;
    public:
        Dequeue(int n){
            size = n;
            arr = new int[n];
            front = rear = -1;
        }
        bool isEmpty(){
            return front == -1;
        }
        bool isFull(){
            return (rear+1)%size == front;
        }
        void push_front(){
            if(isEmpty()){
                front = rear = 0;
                arr[0] = x;
                return;
            }else if(isFull()){
                return;
            }else {
                front = (front - 1 + size) % size;
                arr[front]  = x;
                return;
            }
        }
        void push_back(int x){
            if(isEmpty()){
                front = rear = 0;
                arr[0] = x;
            }else if(isFull()){
                return;
            }else{
                rear = (rear+1)%size;
                arr[rear] = x;
                return;
            }
        }
        void pop_front(){
            if(isEmpty()){
                return;
            }else{
                if(front == rear) front = rear = -1;
                else front = (front + 1) % size;
            }
        }
        void pop_back(){
            if(isEmpty()) return;
            else{
                if(front == rear) front = rear = -1;
                else rear = (rear - 1 + size) % size;
            }
        }
    }

// how deque is implemeted in stl
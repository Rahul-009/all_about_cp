    Class Node{
    public:
        int data;
        Node *perv;
        Node *next;

        Node(int val){
            data = val;
            prev = NULL;
            next = NULL;
        }
    };

// insert at start
    if(head == NULL)
        head = new Node(5);
    Node *temp = new Node(5);
    temp->next = head;
    head->prev = temp;
    head = temp;

// insert at end
    Node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    Node *temp = new Node(5);
    curr->next = temp;
    temp->prev = curr;

// convert array into linked list
    Node *head, *tail;
    head = tail = NULL;

    for(int i=0; i<5; i++){
        if(head == NULL){
            head = new Node(arr[i]);
            tail = head;
        }else{
            Node *temp = new Node(arr[i]);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

// recursion
    Node* createDLL(int arr[], int index, int size, Node* back){
        if(index == size) return NULL;
        Node *temp = new Node(arr[index]);
        temp->prev = back;

        temp->next = createDLL(arr, index+1, size, temp)
        return temp;
    }
    int main(){
        head = createDLL(arr, 0, n, NULL);
    }

// insertion at any point
    int pos = 2;
    Node *curr = head;
    while(--pos){
        curr = curr->next;
    }
    Node *temp = new Node(5);
    temp->next = curr->next;
    temp->prev = curr;
    curr->next = temp;
    temp->next->prev = temp;

    if(pos == 0){
        // insert at start
    }else if(curr->next == NULL){
        // insert at end
    }else{
        // insert at middle
    }

// delete
    // delete at start
        if(head != NULL){
            // if only one node exist
            if(head->next == NULL){
                delete head;
                head = NULL;
            }

            // if more than 1 node exist
            else{
                Node *temp = head;
                head = head->next;
                delete temp;
                head->prev = NULL;
            }
        }
    // delete at end
        if(head != NULL){
            // if only one node exist
            if(head->next == NULL){
                delete head;
                head = NULL;
            }

            // if more than 1 node exist
            else{
                Node *curr = head;
                while(curr->next){
                    curr = curr->next;
                }
                curr->prev->next = NULL;
                delete curr;
            }
        }

    // from middle
        Node *curr = head;
        while(--pos){
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;

    // all together
    if(pos == 1){
        if(head != NULL){
            // if only one node exist
            if(head->next == NULL){
                delete head;
                head = NULL;
            }

            // if more than 1 node exist
            else{
                Node *temp = head;
                head = head->next;
                delete temp;
                head->prev = NULL;
            }
        }
    }else{
        Node *curr = head;
        while(--p){
            curr = curr->next;
        }

        if(curr->next == NULL){
            // delete from end
            curr->prev->next = NULL;
            delete curr;
        }else{
            // delete from middle
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
    }



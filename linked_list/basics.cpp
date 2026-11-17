// Node implementation
    Class Node{
    public:
        int data;
        Node *next;

        Node(int val){
            data = val;
            next = NULL;
        }
    }

    int main(){
        Node *head;
        head = new Node(4);
    }

// Insertion
    // Start
    if(head == NULL){
        head = new Node(5);
    }

    Node *temp = new Node(5);
    temp->next = head;
    head = temp;
    ------------------
    int arr[] = {2, 4, 6, 3};
    Node *head;
    head = NULL;

    for(int i=0; i<n; i++){
        if(head == NULL){
            head = new Node(arr[i]);
        }else{
            Node *temp;
            temp = new Node(28)
            temp->next = head;
            head = temp;
        }
    }

    // traverse linked list
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data;
        temp = temp->next;
    }

    // End
    // method-1
    int main(){
        Node *head = NULL;
        for(int i=0; i<n; i++){
            if(head == NULL){
                head = new Node(arr[i]);
            }else{
                Node *tail = head;
                while(tail->next != NULL){
                    tail = tail->next;
                }
                tail->next = new Node(arr[i]);     
            }
        }
    }

    // method 2 - better
    Node *head = NULL;
    Node *tail = NULL;
    for(int i=0; i<n; i++){
        if(head == NULL){
            head = new Node(arr[i]);
            tail = head;
        }else{
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
    }

    // recursive
    arr[] = {2, 4, 6, 8, 10}

    // head->2->4->6->8->10
    Node* createLinkedList(int arr[], int index, int size){
        // base case
        if(index == size) 
            return NULL;

        Node *temp;
        temp = new Node(arr[index]);
        temp->next = createLinkedList(arr, index+1, size);

        return temp;
    } 

    // 2<-4<-6<-8<-10-<head
    Node& createLinkedList(int arr[], int index, int size, Node* prev){
        if(index == size) return prev;
        Node *temp;
        temp = new Node(arr[index]);
        temp=>next = prev;
        return createLinkedList(arr, index+1, size, temp); 
    }

    // Middle
    int x = 3 // insert position
    int val = 30;

    Node *temp = head;
    x--;
    while(x--){
        temp = temp->next;
    }

    Node *temp2 = new Node(val);
    temp2->next = temp->next;
    temp->next = temp2;

// Deletion
    // first
    if(head != NULL){
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    // last
    if(head != NULL){ // edge case 1 : size 0
        if(head->next == NULL){ // edge case 2 : linked list size 1
            Node *temp = head;
            delete temp;
            head = NULL;
        }else{ // size more than 1
            Node *curr = head;
            Node *prev = NULL;
            while(curr != NULL){
                prev = curr;
                curr = curr->next;
            }
            delete curr;
            prev->next = NULL;
        }
    }
    // particular in middle
    if(x == 1){
        Node *temp = head;
        head = head->next;
        delete temp;

        return head;
    }

    Node *curr = head;
    Node *prev = NULL;
    x--:
    while(x--){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    return head

    // recursive

// Search
// Update
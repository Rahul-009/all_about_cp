// reverse linked list 
    // store in array | then create reverse linked list

    // reverse without changing the address | no extra memory

    // recursion

// middle of linked list
    // count first | then find middle | traverse again | need to traverse 2 times
    int count = 0;
    Node *temp = head;

    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    count/=2;
    temp = head;
    while(count--){
        temp = temp->next;
    }

    return temp;
    // slow & fast pointer | single traversal
    Node *fast = head;
    Node *slow = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

// Remove nth node from end
    int count = 0;
    Node *temp = head;

    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    
    count -= n;
    // edge case : 1st node
    if(count == 0){
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *curr = head;
    while(count--){
        prev = curr;
        curr = curr->next;
    }
    
    prev->next = curr->next;
    delete curr;
    return head;

// Remove every Kth node
    if(k==1) return NULL; // edge case
    
    Node *curr = head, *prev = NULL;
    int count = 1;

    while(curr){
        if(k == count){
            prev->next = curr->next;
            delete curr;
            curr = prev->next
            count = 1;
        }else{
            prev = curr;
            curr = curr->next;
            count += 1;
        }
    }
    return head;

// Rotate linked list
  //method 1
    //edge case
    if(head == NULL || head->next == NULL) return head;

    int count = 0;
    Node *temp = head;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }

    k = k%count; // edge case | if k > count
    if(k == 0) return head;
    count -=k;

    Node *curr = head, *prev = NULL;
    while(count--){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    Node *tail = curr;
    while(tail->next != NULL)
        tail = tail->next;

    tail = head->next;
    head = curr;
    return head;
  // method 2 - using array

// check pallindrome
    // method 1 - using array
    // method 2 - no extra memory

    if(head->next == NULL) return 1; // edge case
    
    // divide into 2 list from middle
    Node* temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    count/=2;
    Node *curr = head, *prev = NULL;

    while(count--){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;

    // reverse the 2nd part
    Node* front = NULL;
    while(curr){
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    // compare 2 list
    Node* head1 = head;
    Node* head2 = prev;

    while(head1){
        if(head1->data != head2->data)
            return 0;
        head1 = head1->next;
        head2 = head2->next;
    }
    return 1;

// Remove Duplicate from sorted linked list
    // using array
        vector<int> ans;
        ans.push_back(head->data);

        Node *curr = head->next;
        while(curr){
            if(ans[ans.size()-1] != curr->data)
                ans.push_back(curr->data);
            curr = curr->next;
        }
        // insert array data in linked list starting from head
        curr = head;
        int index = 0;
        while(index < ans.size()){
            curr->data = ans[index];
            index++;
            curr = curr->next;
        }
        // remove remaining elements
        int size = ans.size();
        curr = head;
        while(size--){
            curr = curr->next;
        }
        curr->next = NULL;
        return head;

    // without extra memory | inplace
        if(!head || !head->next)
            return head; 
        Node *curr = head->next, *prev = head;
        while(curr){
            if(curr->data == prev->data){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }else{
                prev = prev->next;
                curr = curr->next;
            }
        }

// Merge 2 sorted list
    // using extra memory
    // without using extra memory
    Node *head = new Node(0); // dummy node | remove at the end
    Node *tail = head;
    
    while(head1 && head2){
        if(head1->data <= head2->data){
            tail->next = head1;
            head1 = head1->next;
            tail = tail->next;
            tail->next = NULL;
        }else{
            tail->next = head2;
            head2 = head2->next;
            tail = tail->next;
            tail->next = NULL;
        }
    }
    if(head1) tail->next = head1;
    else tail->next = head2;

    // delete dummy first node
    tail = head;
    head = head->next;
    delete tail;
    return head;

// Sort a list which contain 0 1 2
    // can change node value
    Node *curr = head;
    int count0=0, count1=0, count2=0;

    while(curr){
        if(curr->data == 0) count0++;
        else if(curr->data == 1) count1++;
        else count2++
        curr = curr->next;
    }
    curr = head;
    while(count0--){
        curr->data = 0;
        curr = curr->next;
    }
    while(count1--){
        curr->data = 1;
        curr = curr->next;
    }
    while(count2--){
        curr->data = 2;
        curr = curr->next;
    }
    return head;

    // cannot change node value
    Node *head0, *head1, *head2;

// Add 2 number represented by linked list
    // How to traverse from end to start ? reverse 2 linked list and traverse
    node* reverse(Node *curr, Node *prev){
        if(curr == NULL) return prev;

        Node *front = curr->next;
        curr->next = prev;

        return reverse(front, curr);
    }

    int main(){
        Node *first, *second;
        first = reverse(first, NULL);
        second = reverse(second, NULL);
        Node *curr1 = first, *curr2 = second;
        Node *head = NULL;
        Node *tail = NULL;
        while(curr1 && curr2){
            int sum = curr1->data + curr2->data + carry;
            tail->next = new Node(sum%10);
            tail = tail->next;
            curr1= curr1->next;
            curr2 = curr2->next;
            carry = sum/10;
        }

        while(curr1){
            int sum = curr1->data + carry;
            tail->next = new Node(sum%10);

            tail = tail->next;
            curr1 = curr1->next;
            carry = sum/10;
        }
        while(curr2){
            int sum = curr2->data + carry;
            tail->next = new Node(sum%10);

            tail = tail->next;
            curr2 = curr2->next;
            carry = sum/10;
        }
        while(carry){
            tail->next = new Node(carry%10);
            carry /= 10;
        }

    }

// Reverse linked list in group of sizes
    // dummy node
    Node *first  = new Node(0);
    first->next = head;
    head = first;

    Node *second, *prev, *curr, *front;
    int x;
    // main algo
    while(first->next){
        second = first->next;
        prev = first;
        curr = first->next;
        x = k;

        while(x && curr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
            x--;
        }
        first->next = prev;
        second->next = curr;
        first = second;
    }
    // cleanup dummy
    first = head;
    head = head->next;
    delete first;

// Flattening a linked list
    // O(n^2*m)
    Node* merge(Node* head1, Node* head2){
        Node *head = new Node(0); // dummy node
        Node* tail = head;

        while(head1 && head2){
            if(head1->data <= head2->data){
                tail->bottom = head1;
                head1 = head1->bottom;
                tail = tail->bottom;
                tail->bottom = NULL;
            }else{
                tail->bottom = head2;
                head2 = head2->bottom;
                tail = tail->bottom;
                tail->bottom = NULL;
            }
        }

        if(head1){
            tail->bottom = head1;
        }else{
            tail->bottom = head2;
        }
        return head->bottom;
    }

    Node *head1, *head2, *head3;
    while(root->next){
        head1 = root;
        head2 = root->next;
        head3 = root->next->next;

        head1->next = NULL;
        head2->next = NULL;

        root = merge(head1, head2);
        root->next = head3;
    }

// Merge K sorted linked list
    Node* merge(Node* head1, Node* head2){
        Node *head = new Node(0); // dummy node
        Node* tail = head;

        while(head1 && head2){
            if(head1->data <= head2->data){
                tail->next = head1;
                head1 = head1->next;
                tail = tail->next;
                tail->next = NULL;
            }else{
                tail->next = head2;
                head2 = head2->next;
                tail = tail->next;
                tail->next = NULL;
            }
        }

        if(head1){
            tail->next = head1;
        }else{
            tail->next = head2;
        }
        return head->next;
    }

    Node *head = arr[0];
    for(int i=1; i<k; i++){
        head = merge(head, arr[i]);
    }
    return head;

    // optimization - merge sort

// Clone a linked list
    // O(n^2 solution)
    Node* find(Node *curr1, Node *curr2, Node *x){
        if(x == NULL) return NULL;
        while(curr1 != x){
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return curr2;
    }

    Node *hardcopy = new Node(0);
    Node *tailcopy = headcopy;
    Node *temp = head;

    while(temp){
        tailcopy->next = new Node(temp->data);
        tailcopy = tailcopy->next;
        temp = temp->next;
    }
    tailcopy = headcopy;
    headcopy = headcopy->next;
    delete tailcopy;

    tailcopy = headcopy;
    temp = head;

    while(temp){
        tailcopy->arb = find(head, headcopy, temp->arb);
        tailcopy = tailcopy->next;
        temp = temp->next;   
    }
    return head;

    // O(n) solution | O(n) space
    unordered_map<Node*, Node*> m;
    while(temp){
        m[temp] = tailcopy;
        temp = temp->next;
        tailcopy = tailcopy->next;
    }
    tamp = head;
    tailcopy = headcopy;

    while(temp){
        tailcopy->arb = m[tamp->arb];
        tailcopy = tailcopy->next;
        temp = temp->next;
    }
    return headcopy;

    // O(n) time | O(1) space
    // clone without random pointer
    Node *hardcopy = new Node(0);
    Node *tailcopy = headcopy;
    Node *temp = head;

    while(temp){
        tailcopy->next = new Node(temp->data);
        tailcopy = tailcopy->next;
        temp = temp->next;
    }
    tailcopy = headcopy;
    headcopy = headcopy->next;
    delete tailcopy;
    
    tailcopy = headcopy;
    temp = head;

    // insert them in original LL
    Node * curr1 = head, *curr2 = headcopy;
    Node *front1, *front2;
    while(curr1){
        front1 = curr1->next;
        front2 = curr2->next;
        curr1->next = curr2;
        curr2->next = front1;
        curr1 = front1;
        curr2 = front2;
    }

    // assign random pointer to cloned LL
    curr1 = head; 
    while(curr1){
        curr2 = curr1->next;
        if(curr1->arb)
            curr2->arb = curr->arb->next;
        curr1 = curr2->next;
    }

    // disconnect the originals
    curr1->head;
    while(curr1->next){
        front1 = curr1->next;
        curr1->next = front1->next;
        curr1 = front;
    }
    return headCopy;
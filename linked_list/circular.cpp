// circular linked list -> last node points first one 

// Detect Loop in linked list
    // O(n^2) solution | bruteforce
    void check(vector<Node*> vis, Node *curr){
        for(int i=0; i<vis.size(); i++){
            if(vis[i] == curr) return 1;
        }
        return 0; 
    }

    Node *curr = head;
    vector<Node*> vis;
    while(curr != NULL){
        if(check(vis, curr)) 
            return 1;
        vis.push_back(curr);
        curr = curr->next
    }
    return 0;

    // use hash map | O(N) time | O(N) space
    Node *curr = head;
    unordered_map<Node*, bool> vis;
    while(curr != NULL){
        if(vis[vurr] == 1) 
            return 1;
        vis[curr] = 1;
        curr = curr->next
    }
    return 0;

    // O(1) space | slow, fast pointer
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && slow != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return 1;
    }

// Find length of loop

    // check if loop exists
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && slow != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return 1;
    }
    if(fast == NULL || fast->next == NULL) return 0;

    // count loop length | halt fast, move slow until fast reached
    int count = 1;
    slow = fast->next;
    while(slow != fast){
        count++;
        slow = slow->next;
    }

// detect & remove loop
  // method 1
    // check if loop exists
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && slow != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return 1;
    }
    if(fast == NULL || fast->next == NULL) return 0;

    // find starting of loop
        // at meeting point of slow and fast | make slow = head
        // keep moving slow and fast by 1 step
        // the meeting point will be the start of loop
    
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    // now find and remove the last node of cycle
    while(slow->next != fast)
        slow = slow->next;
    slow->next = NULL;

  // method 2 - count number of node in loop


// intersection point in Y shaped linked list
    // method1
    Node *curr1 = head1, *curr2=head2;
    int count1 = 0, count2 = 0;
    
    while(curr1){
        count1++;
        curr1 = curr1->next;
    }
    while(curr2){
        count2++;
        curr2 = curr2->next;
    }
    curr1 = head1, curr2 = head2;

    while(count1 > count2){
        curr1 = curr1->next;
        count1--;
    }
    while(count2 > count1){
        curr2 = curr2->next;
        count2--;
    }
    while(curr1 != curr2){
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    if(!curr1) return -1;

    return curr1->data;

    // method2 
        // make a loop and use slow, fast pointer



// Problem - Linked List Cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// bruteforce
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        
        if(head == NULL) return false;

        while(head->next){
            if(visited.count(head))
                return true;

            visited.insert(head);
            head = head->next;
        }

        return false;
    }
};


// better code
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;

        while(head){
            if(visited.count(head))
                return true;

            visited.insert(head);
            head = head->next;
        }

        return false;
    }
};

// Floyd's Tortoise and Hare Algorithm
// constant memory O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }

        return false;
    }
};
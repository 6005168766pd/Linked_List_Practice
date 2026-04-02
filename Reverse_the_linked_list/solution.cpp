// Approach 1: Recursive Approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* newHead = reverseList(head->next);

        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
};

// Approach 2: Iterative Approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};

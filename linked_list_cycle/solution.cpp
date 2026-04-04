// Approach 1: Using hashset
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;

        while (head) {
            if (s.count(head)) return true;
            s.insert(head);
            head = head->next;
        }

        return false;
    }
};
// Approach 2: Floyd Cycle Detection
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true;
        }

        return false;
    }
};

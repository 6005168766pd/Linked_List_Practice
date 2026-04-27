#  Linked List Cycle II

##  Problem Statement

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return `NULL`.

A cycle exists if a node can be reached again by continuously following the `next` pointer.

---

##  Intuition

Detecting a cycle is not enough — we must find the **exact node where the cycle starts**.

This can be done efficiently using **Floyd’s Cycle Detection Algorithm (Tortoise & Hare)**.

---

##  Approach: Floyd’s Algorithm (Optimal )

###  Core Idea

1. Use two pointers:

   * `slow` moves 1 step
   * `fast` moves 2 steps
2. If they meet → cycle exists
3. Reset one pointer to head
4. Move both one step → they meet at **cycle start**

---

##  Algorithm

1. Initialize:

   * `slow = head`
   * `fast = head`
2. Traverse:

   * Move `slow` by 1 step
   * Move `fast` by 2 steps
3. If they meet:

   * Reset `slow = head`
4. Move both one step:

   * When `slow == fast` → return node
5. If no cycle → return `NULL`

---

##  Code (C++)

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Find cycle start
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return NULL;
    }
};
```

---

##  Intuition (Why it works)

Let:

* Distance from head to cycle start = **L**
* Distance from cycle start to meeting point = **X**

After pointers meet:

* Moving one pointer to head ensures both pointers travel equal distance
* They meet at the **cycle starting node**

---

### Example:

Input:
3 → 2 → 0 → -4
↑       ↓
← ← ← ←

Output:
Node with value 2 (cycle start)

---

##  Complexity

* Time Complexity: **O(n)**
* Space Complexity: **O(1)** 

---

##  Important Notes

* Comparison is based on **node address**, not value
* No modification of list is required
* Works in a single traversal

---

##  Tags

`Linked List` `Two Pointers` `Cycle Detection` `Medium`

---


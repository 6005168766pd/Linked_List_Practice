#  Middle of the Linked List

> LeetCode Problem: Middle of the Linked List
> Difficulty: Easy
> Topic: Linked List, Two Pointers

---

##  Problem Statement

Given the head of a singly linked list, return the **middle node** of the linked list.

If there are two middle nodes, return the **second middle node**.

---

##  Approach (Two Pointer Technique)

We use two pointers:

* **Slow pointer** → moves 1 step at a time
* **Fast pointer** → moves 2 steps at a time

###  Logic:

* When the fast pointer reaches the end,
* The slow pointer will be at the **middle**

---

##  Algorithm

1. Initialize two pointers:

   * `slow = head`
   * `fast = head`
2. Traverse the list:

   * Move `slow` by 1 step
   * Move `fast` by 2 steps
3. When `fast == NULL` or `fast->next == NULL`

   * `slow` will be at the middle
4. Return `slow`

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** O(n)
* **Space Complexity:** O(1)





> 💡 This is the beginning of my Linked List mastery journey. Stay tuned for more!

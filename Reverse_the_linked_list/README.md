# 🔁 Reverse a Linked List

## 📌 Problem Statement

Given the head of a singly linked list, reverse the list and return the new head.

---

##  Intuition

To reverse a linked list, we change the direction of pointers.

Instead of:
1 → 2 → 3 → 4 → NULL

We want:
4 → 3 → 2 → 1 → NULL

---

## ⚙️ Approach 1: Iterative (Best Approach)

###  Idea

Use three pointers to reverse links step by step.

### 🧩 Algorithm

1. Initialize:

   * `prev = NULL`
   * `curr = head`
2. Traverse the list:

   * Store next node → `next = curr->next`
   * Reverse link → `curr->next = prev`
   * Move pointers:

     * `prev = curr`
     * `curr = next`
3. Return `prev` (new head)

### 💻 Code (C++)

```cpp
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
```

---

## 🔁 Approach 2: Recursive

### 💡 Idea

Reverse the rest of the list, then fix the current node.

### 🧩 Algorithm

1. Base case:

   * If `head == NULL` or `head->next == NULL`, return `head`
2. Recursively reverse remaining list
3. Fix current node:

   * `head->next->next = head`
   * `head->next = NULL`
4. Return new head

### 💻 Code (C++)

```cpp
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
```

---

## ⏱️ Complexity

| Approach  | Time Complexity | Space Complexity |
| --------- | --------------- | ---------------- |
| Iterative | O(n)            | O(1)             |
| Recursive | O(n)            | O(n) (stack)     |

---

## 📚 Example

Input:
1 → 2 → 3 → 4 → NULL

Output:
4 → 3 → 2 → 1 → NULL

---

## 🚀 Tags

`Linked List` `Easy` `Recursion` `Pointers`

---


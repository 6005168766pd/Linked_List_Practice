# 🔗 Sort Linked List

## 📌 Problem Statement

Given the head of a singly linked list,
👉 sort the list in **ascending order** and return the sorted list.

---

## 🧪 Example

### Example 1:

```
Input:  4 → 2 → 1 → 3  
Output: 1 → 2 → 3 → 4
```

### Example 2:

```
Input: -1 → 5 → 3 → 4 → 0  
Output: -1 → 0 → 3 → 4 → 5
```

---

## 🚀 Approach

### 🔹 Merge Sort (Optimal Approach)

Since linked lists do not support random access efficiently,
👉 **Merge Sort** is the best choice.

---

## 💡 Steps:

1. **Find the middle** of the linked list
2. **Split** the list into two halves
3. Recursively sort both halves
4. **Merge** the sorted halves

---

## ⚡ Key Idea

* Use **slow & fast pointers** to find middle
* Use **merge logic** (same as merge two sorted lists)
* Divide and conquer approach

---

## 🧠 Algorithm

```
1. If head is NULL or single node → return head
2. Find middle of list using slow-fast pointer
3. Split list into two halves
4. Recursively sort left and right halves
5. Merge both sorted halves
6. Return merged list
```

---

## 💻 Code (C++)

```cpp
class Solution {
public:

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1) tail->next = l1;
        else tail->next = l2;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        return merge(left, right);
    }
};
```

---

## ⏱️ Complexity Analysis

| Complexity | Value                      |
| ---------- | -------------------------- |
| Time       | O(n log n)                 |
| Space      | O(log n) (recursion stack) |

---



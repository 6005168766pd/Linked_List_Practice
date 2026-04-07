# 🔁 Reverse Linked List II

## 📌 Problem Statement

Given the head of a singly linked list and two integers `left` and `right`, reverse the nodes of the list from position `left` to position `right`, and return the modified list.

Positions are **1-indexed**.

---

## 🧠 Intuition

Instead of reversing the entire list, we only reverse a **specific portion** of it.

To do this:

* Locate the node just before position `left`
* Reverse the sublist between `left` and `right`
* Reconnect the reversed portion back to the list

---

## ⚙️ Approach: One Pass In-Place Reversal 🔥

### 💡 Idea

Use a **dummy node** and perform **local reversal** using pointer manipulation.

---

## 🧩 Algorithm

1. Create a dummy node:

   * `dummy->next = head`

2. Move a pointer `prev` to `(left - 1)` position

3. Initialize:

   * `curr = prev->next`

4. Reverse nodes between `left` and `right`:

   * Extract next node and insert it after `prev`

5. Return `dummy->next`

---

## 💻 Code (C++)

```cpp id="k8t9rm"
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        // Step 1: Move prev to (left - 1)
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 2: Reverse sublist
        ListNode* curr = prev->next;

        for (int i = 0; i < right - left; i++) {
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy->next;
    }
};
```

---

## 🔍 Dry Run

### Input:

```
1 → 2 → 3 → 4 → 5  
left = 2, right = 4
```

### Steps:

Reverse sublist:

```
2 → 3 → 4
```

### Output:

```
1 → 4 → 3 → 2 → 5
```

---

## ⏱️ Complexity

* Time Complexity: **O(n)**
* Space Complexity: **O(1)**

---

## ⚠️ Important Notes

* Use a **dummy node** to handle edge cases (like reversing from head)
* Only modify pointers, do not create new nodes
* Works in a single traversal

---

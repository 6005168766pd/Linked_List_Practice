# 🔁 Linked List Cycle

## 📌 Problem Statement

Given the head of a singly linked list, determine if the linked list has a cycle in it.

A cycle exists if a node can be reached again by continuously following the `next` pointer.

Return `true` if there is a cycle, otherwise return `false`.

---

## 🧠 Intuition

If there is a cycle, traversal will never reach `NULL`.

We need a way to detect whether we are revisiting nodes efficiently.

---

## ⚙️ Approach 1: HashSet (Brute Force)

### 💡 Idea

Store visited nodes in a set.
If we encounter the same node again → cycle exists.

---

### 🧩 Algorithm

1. Initialize an empty set
2. Traverse the list:

   * If node already exists in set → return `true`
   * Else insert node into set
3. If traversal ends → return `false`

---

### 💻 Code (C++)

```cpp
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
```

---

### ⏱️ Complexity

* Time: **O(n)**
* Space: **O(n)**

---

## ⚡ Approach 2: Floyd’s Cycle Detection (Optimal 🔥)

### 💡 Core Idea

Use two pointers:

* `slow` → moves 1 step
* `fast` → moves 2 steps

If a cycle exists, they will eventually meet.

---

### 🧩 Algorithm

1. Initialize:

   * `slow = head`
   * `fast = head`
2. Traverse:

   * `slow = slow->next`
   * `fast = fast->next->next`
3. If at any point `slow == fast` → cycle exists
4. If `fast == NULL` → no cycle

---

### 💻 Code (C++)

```cpp
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
```

---

### 🔍 Intuition (Why it works)

* In a cycle, fast pointer gains on slow pointer
* Eventually, fast will "lap" slow → they meet

---

### ⏱️ Complexity

* Time: **O(n)**
* Space: **O(1)** ✅

---

## 📚 Example

### Example 1:

Input:
3 → 2 → 0 → -4
↑     ↓
← ← ← ←

Output:
true

---

### Example 2:

Input:
1 → 2 → NULL

Output:
false

---

## ⚠️ Important Notes

* We compare **node addresses**, not values
* No modification of list is required
* Works efficiently for large inputs

---

## 🚀 Tags

`Linked List` `Two Pointers` `Fast & Slow Pointer` `Easy`

---



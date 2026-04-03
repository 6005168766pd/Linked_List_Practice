# 🔗 Intersection of Two Linked Lists

## 📌 Problem Statement

Given the heads of two singly linked lists `headA` and `headB`, return the node at which the two lists intersect. If the two linked lists have no intersection, return `NULL`.

> ⚠️ Intersection means **same node in memory**, not same value.

---

## 🧠 Intuition

If two linked lists intersect, they will share the same tail nodes after the intersection point.

The main challenge is:

* Lists may have **different lengths**
* We need to align them **without extra space**

---

## ⚙️ Approach 1: HashSet (Brute Force)

### 💡 Idea

* Store all nodes of list A in a hash set
* Traverse list B and check the first node that appears in the set

---

### 🧩 Algorithm

1. Traverse list A → store each node in a set
2. Traverse list B:

   * If node exists in set → return that node
3. If no match → return NULL

---

### 💻 Code (C++)

```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;

        while (headA) {
            s.insert(headA);
            headA = headA->next;
        }

        while (headB) {
            if (s.count(headB)) return headB;
            headB = headB->next;
        }

        return NULL;
    }
};
```

---

### ⏱️ Complexity

* Time: **O(n + m)**
* Space: **O(n)**

---

## ⚡ Approach 2: Two Pointer (Optimal 🔥)

### 💡 Core Idea

Make both pointers traverse equal distance by switching heads.

---

### 🧩 Algorithm

1. Initialize:

   * `a = headA`
   * `b = headB`
2. Traverse:

   * If `a == NULL` → move to `headB`
   * If `b == NULL` → move to `headA`
3. Continue until `a == b`
4. Return node (`intersection` or `NULL`)

---

### 💻 Code (C++)

```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }

        return a;
    }
};
```

---

### 🔍 Intuition (Why it works)

Let:

* Length of A = `x + c`
* Length of B = `y + c`
* `c` = common part

After switching:

* Pointer A travels → `x + c + y`
* Pointer B travels → `y + c + x`

👉 Both travel equal distance → meet at intersection

---

### ⏱️ Complexity

* Time: **O(n + m)**
* Space: **O(1)** ✅

---

## 📚 Example

### Example 1:

Input:
A: 1 → 2 → 3 → 7 → 8
B:       4 → 5 → 7 → 8

Output:
7 (intersection node)

---

### Example 2 (No Intersection):

Input:
A: 1 → 2 → 3 → 4 → 5
B: 5 → 6 → 7 → 8 → 9

Output:
NULL

---

## ⚠️ Important Notes

* Comparison is based on **node address**, not value
* Lists remain unchanged
* Works even if lengths differ

---

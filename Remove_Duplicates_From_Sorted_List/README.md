# 🧹 Remove Duplicates from Sorted List

## 📌 Problem Statement

Given the head of a **sorted** linked list, delete all duplicates such that each element appears only once.
Return the linked list sorted as well.

---

## 🧠 Intuition

Since the linked list is **sorted**, duplicate values will always be **adjacent**.

So, we can simply:

* Compare the current node with the next node
* If they are equal → skip the next node

---

## ⚙️ Approach: One Pass In-Place Removal

### 💡 Idea

Traverse the list and remove duplicates by adjusting pointers without using extra space.

---

## 🧩 Algorithm

1. Initialize:

   * `curr = head`

2. Traverse the list while:

   * `curr != NULL` and `curr->next != NULL`

3. At each step:

   * If `curr->val == curr->next->val`:

     * Skip duplicate:

       ```cpp
       curr->next = curr->next->next;
       ```
   * Else:

     * Move forward:

       ```cpp
       curr = curr->next;
       ```

4. Return `head`

---

## 💻 Code (C++)

```cpp id="x8c9tp"
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};
```

---

## 📚 Example

### Input:

```text id="3qv2dl"
1 → 1 → 2 → 3 → 3
```

### Output:

```text id="7eqzqj"
1 → 2 → 3
```

---

## ⏱️ Complexity

* Time Complexity: **O(n)**
* Space Complexity: **O(1)**

---

## ⚠️ Important Notes

* Works because the list is **sorted**
* No extra data structures are used
* Modifies the list **in-place**

---

## 🚀 Tags

`Linked List` `Easy` `In-Place`

---



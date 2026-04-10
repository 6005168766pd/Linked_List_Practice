# 🧩 Remove Nth Node From End of List

## 📌 Problem Statement

Given the head of a singly linked list, remove the **Nth node from the end** of the list and return its head.

---

## 🧪 Example

### Example 1:

```
Input:  1 → 2 → 3 → 4 → 5, n = 2  
Output: 1 → 2 → 3 → 5
```

### Example 2:

```
Input:  1, n = 1  
Output: NULL
```

---

## 🚀 Approach

### 🔹 Two Pointer Technique (Optimal)

We use two pointers:

* `fast`
* `slow`

### 💡 Steps:

1. Move `fast` pointer **n+1 steps ahead**
2. Move both `fast` and `slow` together
3. When `fast` reaches the end:

   * `slow` will be just before the node to delete
4. Update pointers to remove the target node

---

## ⚡ Key Idea

Using a **dummy node** helps handle edge cases easily (like deleting the head node).

---

## 🧠 Algorithm

```
1. Create a dummy node pointing to head
2. Initialize fast and slow = dummy
3. Move fast pointer n+1 steps ahead
4. Move both pointers until fast reaches NULL
5. Delete slow->next node
6. Return dummy->next
```

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete target node
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return dummy->next;
    }
};
```

---

## ⏱️ Complexity Analysis

| Complexity | Value |
| ---------- | ----- |
| Time       | O(n)  |
| Space      | O(1)  |

---

## ⚠️ Edge Cases

* Single node list
* Removing head node
* n equals length of list

---

## 🔥 Key Learnings

* Two pointer (fast & slow) technique
* Handling edge cases with dummy node
* One-pass solution

---


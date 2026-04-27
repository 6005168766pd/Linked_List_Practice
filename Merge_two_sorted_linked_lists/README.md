#  Merge Two Sorted Linked Lists

##  Problem Statement

You are given the heads of two **sorted linked lists** `list1` and `list2`.

 Merge the two lists into a single **sorted linked list**
 Return the head of the merged list

---

##  Example

### Example 1:

```
Input:  list1 = 1 → 2 → 4  
        list2 = 1 → 3 → 4  

Output: 1 → 1 → 2 → 3 → 4 → 4
```

### Example 2:

```
Input:  list1 = NULL  
        list2 = 0  

Output: 0
```

---

##  Approach

###  Iterative Approach (Optimal)

We use a **dummy node** to simplify merging.

###  Steps:

1. Create a dummy node
2. Use a pointer `tail` to build the new list
3. Compare nodes of both lists:

   * Attach the smaller node to `tail`
   * Move that list forward
4. After one list ends:

   * Attach the remaining part of the other list

---

##  Key Idea

 Always pick the **smaller node**
 Maintain sorted order while merging

---

##  Algorithm

```
1. Create dummy node
2. Initialize tail = dummy
3. While both lists are not NULL:
     - Compare values
     - Attach smaller node to tail
     - Move pointer forward
4. Attach remaining nodes
5. Return dummy->next
```

---

##  Code (C++)

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach remaining nodes
        if (list1 != NULL) tail->next = list1;
        else tail->next = list2;

        return dummy->next;
    }
};
```

---

##  Complexity Analysis

| Complexity | Value    |
| ---------- | -------- |
| Time       | O(n + m) |
| Space      | O(1)     |

---



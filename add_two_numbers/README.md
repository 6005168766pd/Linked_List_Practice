#  Add Two Numbers (Linked List)

##  Problem Statement

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in **reverse order**, and each node contains a single digit.

Add the two numbers and return the sum as a linked list.

---

##  Intuition

This problem is similar to **adding numbers manually**:

* Add digits one by one
* Maintain a **carry**
* Move to the next nodes

---

##  Approach: Iterative with Carry (Optimal )

###  Idea

Traverse both linked lists simultaneously and:

* Add corresponding digits
* Handle carry
* Build the result list

---

##  Algorithm

1. Initialize:

   * `carry = 0`
   * Dummy node for result list

2. Traverse while:

   * `l1` OR `l2` OR `carry` exists

3. At each step:

   * `sum = carry`
   * Add values of `l1` and `l2` if present
   * Create new node with `(sum % 10)`
   * Update `carry = sum / 10`

4. Return `dummy->next`

---

##  Code (C++)

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            temp = temp->next;
        }

        return dummy->next;
    }
};
```

---

## 📚 Example

### Example:

Input:
l1 = 2 → 4 → 3
l2 = 5 → 6 → 4

Output:
7 → 0 → 8

Explanation:

```text
342 + 465 = 807
```

---

## ⏱️ Complexity

* Time Complexity: **O(max(n, m))**
* Space Complexity: **O(max(n, m))**

---

## ⚠️ Important Notes

* Digits are stored in **reverse order**
* Result list is also in reverse order
* Handles different lengths automatically
* Carry can create an extra node

---

## 🚀 Tags

`Linked List` `Math` `Simulation` `Medium`

---

## 🎯 Interview Tip

> “This is similar to manual addition — process digit by digit and maintain carry.”

---

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      // Approach 1 : Using Hashset
        // unordered_set<ListNode*> set;
        // ListNode* temp1 = headA;
        // while(temp1){
        //     set.insert(temp1);
        //     temp1=temp1->next;
        // }
        // ListNode* temp2 = headB;
        // while(temp2){
        //     if(set.find(temp2) != set.end()){
        //         return temp2;
        //     }
        //     temp2=temp2->next;
        // }
        // return NULL;
        // Approach 2: Using two pointers
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while(temp1 != temp2){
            temp1 = (temp1==NULL)? headB : temp1->next;
            temp2 = (temp2==NULL) ? headA : temp2->next;
        }
        return temp1;
             }
};

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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return NULL;
        
        if (head -> next) {
            if (head -> next -> val == head -> val) {
                head -> next = head -> next -> next;
                deleteDuplicates(head);
            } else {
                deleteDuplicates(head -> next);
            }
        }
        
        return head;
    }
};

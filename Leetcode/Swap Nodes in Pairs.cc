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
    ListNode *swapPairs(ListNode *head) {
        if (!head) {
            return NULL;
        }
        ListNode* now = head;
        ListNode* next= head->next;
        
        if (!next) {
            return now;
        } else {
            swap(head->val, next->val);
            swapPairs(next->next);
            return head;
        }
    }
};

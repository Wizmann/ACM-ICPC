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
        if (!head) {
            return head;
        }
        ListNode *ptr = head;
        while (ptr) {
            ListNode *next = ptr -> next;
            while (next && next -> val == ptr -> val) {
                next = next -> next;
            }
            ptr -> next = next;
            ptr = next;
        }
        return head;
    }
};

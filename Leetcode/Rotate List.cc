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
    ListNode *rotateRight(ListNode *head, int k) {
        int len = 0;
        ListNode *ptr = head;
        ListNode *pre = NULL;
        while (ptr) {
            len++;
            pre = ptr;
            ptr = ptr->next;
        }
        
        if (!len) return NULL;
        k %= len;
        if (!k) return head;
        else k = len - k;
        
        pre->next = head;
        ptr = head;
        pre = NULL;
        while (k--) {
            pre = ptr;
            ptr = ptr->next;
        }
        pre->next = NULL;
        return ptr;
    }
};

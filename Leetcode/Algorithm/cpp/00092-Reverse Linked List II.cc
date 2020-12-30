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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || m == n) {
            return head;
        }
        ListNode ln(-1);
        ln.next = head;
        
        ListNode *ptr = &ln;
        for (int i = 0; i < m - 1; i++) {
            ptr = ptr -> next;
        }
        do_reverse(ptr, ptr -> next, n - m + 1);
        return ln.next;
    }
private:
    void do_reverse(ListNode* &lead, ListNode* head, int k)
    {
        ListNode *pre = NULL;
        ListNode *ptr = head, *next = NULL;
        for (int i = 0; i < k; i++) {
            next = ptr -> next;
            ptr -> next = pre;
            pre = ptr;
            ptr = next;
        }
        head -> next = ptr;
        lead -> next = pre;
    }
};

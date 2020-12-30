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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *res = NULL, *tail = NULL;
        while (l1 || l2) {
            int val1 = l1? l1 -> val: INT_MAX;
            int val2 = l2? l2 -> val: INT_MAX;
            if (val1 < val2) {
                if (!res) {
                    res = l1;
                    tail = l1;
                } else {
                    tail -> next = l1;
                    tail = l1;
                }
                l1 = l1 -> next;
            } else {
                if (!res) {
                    res = l2;
                    tail = l2;
                } else {
                    tail -> next = l2;
                    tail = l2;
                }
                l2 = l2 -> next;
            }
        }
        return res;
    }
};

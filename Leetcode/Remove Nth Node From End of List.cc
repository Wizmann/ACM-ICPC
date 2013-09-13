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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int x = 0;
        return _do_remove(NULL, head, n, x);
    }
    
    ListNode *_do_remove(ListNode *pre, ListNode *now, int n, int &x) {
        if (now -> next) {
            _do_remove(now, now -> next, n, x);
        } else {
            x = 1;
        }
        ListNode *res = now;
        if (x == n) {
            if (NULL == pre) {
                res = now -> next;
            } else {
                pre -> next = now -> next;
                res = NULL;
            }
            delete now;
        }
        x++;
        return res;
    }
};

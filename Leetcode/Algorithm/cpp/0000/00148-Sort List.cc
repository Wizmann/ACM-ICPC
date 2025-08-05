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
    ListNode *sortList(ListNode *head) {
        if (!head) return NULL;
        ListNode *left, *right;
        left = right = NULL;
        
        ListNode *flag = head;
        head = head -> next;
        
        int cnt = 0;
        while (head) {
            ListNode *next = head -> next;
            if (head -> val > flag -> val ) {
                head -> next = left;
                left = head;
            } else {
                head -> next = right;
                right = head;
            }
            head = next;
            cnt++;
        }
        
        left = sortList(left);
        right = sortList(right);
        
        ListNode *res = left;
        ListNode *res_tail = left;
        
        while (res_tail) {
            if (!(res_tail -> next)) break;
            res_tail = res_tail -> next;
        }
        
        if (res) {
            res_tail -> next = flag;
        } else {
            res = flag;
        }
        flag -> next = right;
        
        return res;
    }
};

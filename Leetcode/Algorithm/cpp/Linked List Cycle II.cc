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
    ListNode *detectCycle(ListNode *head) {
        ListNode *a = head;
        ListNode *b = head;
        
        while (a && b) {
            if (a -> next) a = a -> next;
            else a = NULL;
            if (b -> next && b -> next -> next) b = b -> next -> next;
            else b = NULL;
            
            if (a == b) break;
        }
        
        if (!a || !b) return NULL;
        
        a = head;
        while (a != b) {
            a = a -> next;
            b = b -> next;
        }
        return a;
    }
};

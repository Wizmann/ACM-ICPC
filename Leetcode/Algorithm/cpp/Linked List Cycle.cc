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
    bool hasCycle(ListNode *head) {
        ListNode *a, *b;
        a = b = head;
        
        while (a && b) {
            
            if (a && a -> next) a = a -> next -> next;
            else a = NULL;
            
            if (b) b = b -> next;
            
            if (a && b && a == b) return true;
        }
        return false;
    }
};

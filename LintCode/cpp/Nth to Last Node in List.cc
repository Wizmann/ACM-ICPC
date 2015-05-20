/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        ListNode* first = head;
        ListNode* second = head;
        
        for (int i = 0; i < n; i++) {
            if (first) {
                first = first->next;
            }
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        return second;
    }
};




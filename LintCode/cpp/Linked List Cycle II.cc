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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return NULL;
        }
        ListNode *a, *b;
        a = b = head;
        while (true) {
            a = a->next;
            b = b->next;
            if (b) {
                b = b->next;
            }
            if (a == b || a == NULL || b == NULL) {
                break;
            }
        }
        if (a == NULL ||  b == NULL) {
            return NULL;
        }
        b = head;
        while (a != b) {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};




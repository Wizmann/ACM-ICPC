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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dumb(-1);
        ListNode *ptr = &dumb;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            } else {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
            ptr->next = NULL;
        }
        
        while (l1) {
            ptr->next = l1;
            l1 = l1->next;
            ptr = ptr->next;
            ptr->next = NULL;
        }
        
        while (l2) {
            ptr->next = l2;
            l2 = l2->next;
            ptr = ptr->next;
            ptr->next = NULL;
        }
        return dumb.next;
    }
};

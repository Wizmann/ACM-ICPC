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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast && slow) {
            if (fast) {
                fast = fast->next;
            }
            if (fast == slow) {
                return true;
            }
            if (fast) {
                fast = fast->next;
            }
            if (fast == slow) {
                return true;
            }
            
            slow = slow->next;
        }
        return false;
    }
};




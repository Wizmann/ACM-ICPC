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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            if (!next) {
                break;
            }
            if (cur->val == next->val) {
                cur->next = next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};

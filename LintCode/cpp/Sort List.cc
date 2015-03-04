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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        
        int u = head->val;
        int ptr = 0;
        
        ListNode* left = NULL;
        ListNode* left_tail = NULL;
        
        ListNode* right = NULL;
        ListNode* right_tail = NULL;
        
        ListNode* cur = head->next;
        
        while (cur) {
            ListNode* next = cur->next;
            ptr ^= (cur->val == u);
            if (cur->val < u || (cur->val == u && ptr == 0)) {
                if (!left) {
                    left = left_tail = cur;
                } else {
                    left_tail->next = cur;
                    left_tail = cur;
                }
                left_tail->next = NULL;
            } else {
                if (!right) {
                    right = right_tail = cur;
                } else {
                    right_tail->next = cur;
                    right_tail = cur;
                }
                right_tail->next = NULL;
            }
            cur = next;
        }
        
        left = sortList(left);        
        right = sortList(right);
        
        head->next = NULL;
        if (!left) {
            head->next = right;
            return head;
        }
        cur = left;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = head;
        head->next = right;
        return left;
    }
};

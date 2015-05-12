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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        ListNode *left = nullptr;
        ListNode *left_tail = nullptr;
        ListNode *right = nullptr;
        ListNode *right_tail = nullptr;
        
        while (head) {
            if (head->val < x) {
                if (left == nullptr) {
                    left = left_tail = head;
                } else {
                    left_tail->next = head;
                    left_tail = left_tail->next;
                }
            } else {
                if (right == nullptr) {
                    right = right_tail = head;
                } else {
                    right_tail->next = head;
                    right_tail = right_tail->next;
                }
            }
            head = head->next;
        }
        if (!left) {
            left = right;
        } else {
            left_tail->next = right;
        }
        if (right) {
            right_tail->next = nullptr;
        }
        return left;
    }
};




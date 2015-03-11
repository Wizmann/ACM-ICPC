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
        if (!head) {
            return NULL;
        }

        ListNode* pivot = head;
        ListNode* t = head->next;

        int flag = 0;

        ListNode* left = NULL;
        ListNode* right = NULL;

        while (t) {
            ListNode* next = t->next;
            if (t->val < pivot->val
                    || (flag && t->val == pivot->val)) {
                t->next = left;
                left = t;
            } else {
                t->next = right;
                right = t;
            }

            flag ^= (t->val == pivot->val);
            t = next;
        }
        left = sortList(left);
        right = sortList(right);

        pivot->next = right;
        if (!left) {
            return pivot;
        }
        ListNode* left_tail = left;
        while (left_tail->next) {
            left_tail = left_tail->next;
        }
        left_tail->next = pivot;
        return left;
    }
};



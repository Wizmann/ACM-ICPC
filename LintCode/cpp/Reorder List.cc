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
     * @return: void
     */
    void reorderList(ListNode *head) {
        if (!head) {
            return;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (true) {
            if (fast) {
                fast = fast->next;
            }
            if (fast) {
                fast = fast->next;
            }
            if (!fast) {
                break;
            }
            slow = slow->next;
        }
        ListNode *left = head;
        ListNode *right = slow->next;
        slow->next = nullptr;
        
        right = reverse_linked_list(nullptr, right);
        
        head = nullptr;
        ListNode *tail = nullptr;
        
        
        while (left || right) {
            if (!head) {
                head = tail = left;
            } else {
                tail->next = left;
                tail = tail->next;
            }
            left = left->next;
            
            if (right) {
                tail->next = right;
                tail = tail->next;
                right = right->next;
            }
        }
        tail->next = nullptr;
    }
private:
    ListNode* reverse_linked_list(ListNode *pre, ListNode *cur) {
        if (cur == nullptr) {
            return pre;
        }
        ListNode *next = cur->next;
        cur->next = pre;
        return reverse_linked_list(cur, next);
    }
};




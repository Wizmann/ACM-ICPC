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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            }
        }
        
        ListNode* a = head;
        ListNode* b = reverse_singly_linked_list(slow);
        
        while (b) {
            if (a->val != b->val) {
                return false;
            }
            a = a->next;
            b = b->next;
        }
        return true;
    }
private:
    ListNode* reverse_singly_linked_list(ListNode* cur) {
        return do_reverse(nullptr, cur);
    }
    
    ListNode* do_reverse(ListNode* pre, ListNode* cur) {
        ListNode* next = cur->next;
        cur->next = pre;
        if (next == nullptr) {
            return cur;
        }
        return do_reverse(cur, next);
    }
};
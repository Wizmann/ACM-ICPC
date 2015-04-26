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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode fake_head(-1);
        fake_head.next = head;
        
        ListNode* ptr = &fake_head;
        
        while (ptr) {
            if (ptr->next && ptr->next->val == val) {
                do_remove_next(ptr);
            } else {
                ptr = ptr->next;
            }
        }
        return fake_head.next;
    }
private:
    void do_remove_next(ListNode* head) {
        if (head->next->next == nullptr) {
            delete head->next;
            head->next = NULL;
        } else {
            ListNode* next = head->next->next;
            delete head->next;
            head->next = next;
        }
    }
};

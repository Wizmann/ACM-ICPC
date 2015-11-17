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
    /**
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy_head(-1);
        do_swap(&dummy_head, head);
        
        ListNode* ptr = dummy_head.next;
        return dummy_head.next;
    }
private:
    void do_swap(ListNode* pre, ListNode* cur) {
        if (cur == nullptr) {
            return;
        }
        ListNode* next = cur->next;
        if (next == nullptr) {
            pre->next = cur;
            return;
        }
        ListNode* next_next = next->next;
        pre->next = next;
        next->next = cur;
        cur->next = nullptr;
        do_swap(cur, next_next);
    }
};

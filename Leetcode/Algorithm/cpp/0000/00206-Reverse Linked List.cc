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
    ListNode* reverseList(ListNode* head) {
        return do_reverseList(nullptr, head);
    }
private:
    ListNode* do_reverseList(ListNode* pre, ListNode* cur) {
        if (cur == nullptr) {
            return pre;
        }
        auto next = cur->next;
        cur->next = pre;
        return do_reverseList(cur, next);
    }
};

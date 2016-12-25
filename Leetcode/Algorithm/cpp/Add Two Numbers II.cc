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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = get_length(l1);
        int len2 = get_length(l2);
        
        auto p = do_addTwoNumbers(l1, l2, len1 - len2, true);
        return p.first;
    }
private:
    pair<ListNode*, int> do_addTwoNumbers(ListNode* l1, ListNode* l2, int skip, bool is_first) {
        pair<ListNode*, int> p = {nullptr, 0};
        
        if (l1 == nullptr && l2 == nullptr) {
            return p;
        }
        
        int cur = 0;
        
        if (skip > 0) {
            cur = l1->val;
            p = do_addTwoNumbers(l1->next, l2, skip - 1, false);
        } else if (skip < 0) {
            cur = l2->val;
            p = do_addTwoNumbers(l1, l2->next, skip + 1, false);
        } else {
            cur = l1->val + l2->val;
            p = do_addTwoNumbers(l1->next, l2->next, skip, false);
        }
        
        cur += p.second;
        ListNode* head = new ListNode(cur % 10);
        head->next = p.first;
        
        int g = cur / 10;
        if (is_first && g) {
            ListNode* new_head = new ListNode(g);
            new_head->next = head;
            return {new_head, 0};
        }
        return {head, g};
    }
    
    int get_length(ListNode* head) {
        int res = 0;
        while (head) {
            res++;
            head = head->next;
        }
        return res;
    }
};

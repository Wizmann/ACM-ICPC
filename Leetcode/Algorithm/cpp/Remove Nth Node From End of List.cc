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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode lead(-1);
        lead.next = head;
        dfs(&lead, n + 1);
        return lead.next;
    }
private:
    int dfs(ListNode* cur, int pos) {
        if (!cur) {
            return 0;
        }
        int p = dfs(cur->next, pos) + 1;
        if (p == pos) {
            ListNode* t = cur->next;
            ListNode* tt = t->next;
            cur->next = tt;
            delete t;
        }
        return p;
    }
};

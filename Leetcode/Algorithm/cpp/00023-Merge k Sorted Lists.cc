/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct cmp {
    bool operator() (const ListNode* a, const ListNode* b) {
        if (!a) {
            return false;
        }
        if (!b) {
            return true;
        }
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return NULL;
        }
        ListNode *head = NULL, *cur = NULL;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto node: lists) {
            pq.push(node);
        }
        while (!pq.empty()) {
            auto now = pq.top();
            pq.pop();
            if (!now) {
                continue;
            }
            auto next = now->next;
            if (!head) {
                head = cur = now;
            } else {
                cur->next = now;
                cur = cur->next;
            }
            cur->next = NULL;
            if (next) {
                pq.push(next);
            }
        }
        return head;
    }
};

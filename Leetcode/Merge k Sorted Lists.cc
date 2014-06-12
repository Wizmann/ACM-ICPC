/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
#include <queue>


class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *res = NULL;
        ListNode *tail = NULL;
        priority_queue<Pointer, vector<Pointer>, greater<Pointer> > pq;
        if (lists.empty()) {
            return NULL;
        }
        for (int i = 0; i < (int)lists.size(); i++) {
            if (!lists[i]) continue;
            pq.push(Pointer(lists[i] -> val, i));
        }
        while (true) {
            if (pq.empty()) break;
            
            Pointer now = pq.top();
            pq.pop();
            
            int ptr = now.ptr;
            int val = now.val;
            
            if (!res) {
                res = tail = new ListNode(val);
            } else {
                tail -> next = new ListNode(val);
                tail = tail -> next;
            }
            lists[ptr] = lists[ptr] -> next;
            if (lists[ptr]) {
                pq.push(Pointer(lists[ptr] -> val, ptr));
            }
        }
        return res;
    }
private:
    struct Pointer {
        int val;
        int ptr;
        Pointer(int ival, int iptr): val(ival), ptr(iptr) {}
        
        bool operator > (const Pointer& p) const {
            return val > p.val;
        }
    };
};

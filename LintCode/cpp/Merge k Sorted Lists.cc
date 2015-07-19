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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, 
                vector<ListNode*>, 
                function<bool(ListNode*, ListNode*)> > pq(
            [](const ListNode* a, const ListNode* b) -> bool {
                auto aa = a? a->val: INF;
                auto bb = b? b->val: INF;
                return aa > bb;
            });
        
        for (auto l: lists) {
            pq.push(l);
        }
        
        ListNode dummy_head(-1);
        ListNode* ptr = &dummy_head;
        
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            
            if (p == nullptr) {
                continue;
            }
            ptr->next = p;
            ptr = ptr->next;
            
            p = p->next;
            pq.push(p);
        }
        ptr->next = nullptr;
        return dummy_head.next;
    }
private:
    static const int INF = 0x3f3f3f3f;
};




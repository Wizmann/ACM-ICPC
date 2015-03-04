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
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        int n = hashTable.size();
        int nn = n * 2;

        vector<ListNode*> rehashTable;
        rehashTable.resize(nn);
        fill(rehashTable.begin(), rehashTable.end(), nullptr);

        for (auto& p: hashTable) {
            while (p) {
                auto q = p->next;
                int v = p->val;
                int u = ((v % nn) + nn) % nn;
                p->next = rehashTable[u];
                rehashTable[u] = p;
                p = q;
            }
        }
        
        for (auto& p: rehashTable) {
            if (!p) {
                continue;
            }
            p = reverseLinkedList(p);
        }
        return rehashTable;
    }
private:
    ListNode* reverseLinkedList(ListNode* head) {
        return reverseLinkedList(NULL, head);
    }
    ListNode* reverseLinkedList(ListNode* pre, ListNode* cur) {
        if (cur == NULL) {
            return pre;
        }
        auto next = cur->next;
        cur->next = pre;
        return reverseLinkedList(cur, next);
    }
};


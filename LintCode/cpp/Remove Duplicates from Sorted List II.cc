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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        ListNode dummy(-1);
        dummy.next = head;
        
        int prev = numeric_limits<int>::min();
        ListNode* p = &dummy;
        
        
        while (p) {
            ListNode* q = p->next;
            if (!q) {
                break;
            }
            int value = q->val;
            ListNode *qq = q;
            while (qq && qq->val == value) {
                qq = qq->next;
            }
            if (qq == q->next) {
                p = p->next;
                q = p->next;
            } else {
                p->next = qq;
                q = qq;
            }
        }
        return dummy.next;
    }
};

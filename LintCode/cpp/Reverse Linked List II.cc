/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy_node(1);
        dummy_node.next = head;
        
        ListNode* pre = nullptr;
        ListNode* start = &dummy_node;
        ListNode* end = &dummy_node;
        
        for (int i = 0; i < m; i++) {
            pre = start;
            start = start->next;
        }
        
        for (int i = 0; i < n; i++) {
            end = end->next;
        }
        ListNode* next = end->next;
        
        pre->next = do_reverse(nullptr, start, end);
        start->next = next;
        
        return dummy_node.next;
    }
private:
    ListNode* do_reverse(ListNode* pre, ListNode* start, ListNode* end) {
        ListNode* next = start->next;
        start->next = pre;
        if (start == end) {
            return end;
        }
        return do_reverse(start, next, end);
    }
};


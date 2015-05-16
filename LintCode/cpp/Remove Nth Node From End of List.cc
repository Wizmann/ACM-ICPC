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
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int tmp = 0;
        ListNode dumb(-1);
        dumb.next = head;
        do_remove(&dumb, tmp, n);
        return dumb.next;
    }
private:
    void do_remove(ListNode *head, int &tmp, int n) {
        if (head->next == nullptr) {
            tmp = 1;
            return;
        }
        do_remove(head->next, tmp, n);
        if (tmp == n) {
            head->next = head->next->next;
        }
        tmp += 1;
    }
};




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
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        ListNode dumb(-1);
        ListNode *ptr = &dumb;
        int g = 0;
        
        while (l1 || l2 || g) {
            int a = l1 == nullptr ? 0: l1->val;
            int b = l2 == nullptr ? 0: l2->val;
            ptr->next = new ListNode((a + b + g) % 10);
            g = (a + b + g) / 10;
            ptr = ptr->next;
            l1 = (l1 == nullptr ? l1 : l1->next);
            l2 = (l2 == nullptr ? l2 : l2->next);
        }
        return dumb.next;
    }
};

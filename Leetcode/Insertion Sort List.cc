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
    ListNode *insertionSortList(ListNode *head) {
        ListNode* res = NULL;
        while (head) {
            ListNode *next = head -> next;
            if (!res) {
                res = head;
                head -> next = NULL;
            }
            else {
                if (head -> val < res -> val) {
                    head -> next = res;
                    res = head;
                } else {
                    ListNode *pre = res;
                    ListNode *now = res -> next;
                    while (now) {
                        if (head -> val < now -> val) {
                            break;
                        }
                        pre = now;
                        now = now -> next;
                    }
                    ListNode *t = pre -> next;
                    pre -> next = head;
                    head -> next = t;
                }
            }
            
            head = next;
        }
        return res;
    }
};

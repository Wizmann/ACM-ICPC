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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while (a && b) {
            a = a->next;
            b = b->next;
        }
        if (a == nullptr) {
            a = headA;
            while (b && headB) {
                b = b->next;
                headB = headB->next;
            }
            b = headB;
        }
        if (b == nullptr) {
            b = headB;
            while (a && headA) {
                a = a->next;
                headA = headA->next;
            }
            a = headA;
        }
        while (a && b && a != b) {
            a = a->next;
            b = b->next;
        }
        if (a == b) {
            return a;
        } else {
            return nullptr;
        }
    }
};

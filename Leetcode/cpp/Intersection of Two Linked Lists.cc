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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = get_length(headA);
        int lenB = get_length(headB);
        
        if (lenA > lenB) {
            headA = forward(headA, lenA - lenB);
        } else {
            headB = forward(headB, lenB - lenA);
        }
        
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
private:
    int get_length(ListNode* head) {
        int cnt = 0;
        while (head) {
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* forward(ListNode* head, int cnt) {
        for (int i = 0; i < cnt; i++) {
            if (!head) {
                break;
            }
            head = head->next;
        }
        return head;
    }
};

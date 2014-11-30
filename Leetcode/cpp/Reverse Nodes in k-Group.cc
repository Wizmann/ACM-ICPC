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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode* prev = NULL;
        if (!head) {
            return NULL;
        }
        
        ListNode* cur = head;
        
        while (1) {
            ListNode* tail = move_forward(cur, k - 1);
            
            if (tail == NULL) {
                break;
            }
            ListNode* next = tail->next;
            ListNode* p = reverse_list(tail->next, cur, tail);
            if (prev) {
                prev -> next = p;
            } else {
                head = p;
            }
            prev = cur;
            cur = next;
        }
        return head;
    }
private:
    ListNode* move_forward(ListNode* head, int k) {
        for (int i = 0; i < k; i++) {
            if (head) {
                head = head -> next;
            }
        }
        return head;
    }
    
    ListNode* reverse_list(ListNode* next, ListNode* cur, ListNode* tail) {
        if (cur != tail) {
            ListNode* p = cur->next;
            cur->next = next;
            return reverse_list(cur, p, tail);
        } else {
            tail->next = next;
            return tail;
        }
    }
};

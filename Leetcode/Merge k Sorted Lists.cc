/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

const int INF = 1 << 28;

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = NULL;
        ListNode *now  = NULL;
        while (true) {
            int min_value = INF;
            int min_ptr = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == NULL) {
                    continue;
                } else {
                    if ((lists[i]->val) < min_value) {
                        min_value = lists[i]->val;
                        min_ptr = i;
                    }
                }
            }
            
            if (min_ptr == -1){
                break;
            } else {
                if (!head) {
                    head = lists[min_ptr];
                    now = head;
                } else {
                    now -> next = lists[min_ptr];
                    now = now -> next;
                }
                lists[min_ptr] = lists[min_ptr]->next;
            }
        }
        if (now) {
            now->next = NULL;
        }
        return head;
    }
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) {
            return;
        }
        int len = list_len(head);
        ListNode* half = split_list(head, (len + 1) / 2);
        //walk(head);
        //walk(half);
        half = reverse_list(half, NULL);
        merge_list(head, half);
        //walk(head);
    }
    
    int list_len(ListNode* head, int cnt = 0) {
        if (head) return list_len(head->next, cnt+1);
        else return cnt;
    }
    
    ListNode* split_list(ListNode *head, int sz) {
        if (head && sz) {
            ListNode *next = head -> next;
            if (sz == 1) {
                head -> next = NULL;
            }
            return split_list(next, --sz);
        } else return head;
    }
    
    ListNode* reverse_list(ListNode *now, ListNode *pre) {
        if (!now) return pre;
        ListNode *next = now -> next;
        now -> next = pre;
        return reverse_list(next, now);
    }
    
    void merge_list(ListNode *a, ListNode *b) {
        if (a && b) {
            ListNode *a_next= a -> next;
            a -> next = b;
            merge_list(b, a_next);
        }
    }
    
    void walk(ListNode *head) {
        if (!head) {
            puts("");
            return;
        }
        printf("%d ", head->val);
        walk(head -> next);
    }
};


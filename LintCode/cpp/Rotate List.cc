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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) {
            return nullptr;
        }
        int n = list_len(head);
        k %= n;
        if (k == 0) {
            return head;
        }
        auto* ptr = get_item(head, n - k);
        auto* tail = get_item(head, n);
        auto* new_head = ptr->next;
        ptr->next = nullptr;
        tail->next = head;
        
        return new_head;
    }
private:
    int list_len(ListNode *head) {
        int l = 0;
        while (head) {
            l++;
            head = head->next;
        }
        return l;
    }
    
    ListNode* get_item(ListNode *head, int k) {
        for (int i = 1; i < k; i++) {
            head = head->next;
        }
        return head;
    }
};

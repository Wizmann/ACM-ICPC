class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        int len = length(head);
        if (len == 0 || k % len == 0) {
            return head;
        }
        k = len - k % len;
        
        ListNode* ptr = head;
        for (int i = 0; i < k - 1; i++) {
            ptr = ptr -> next;
        }
        
        ListNode* new_head = ptr -> next;
        ptr -> next = NULL;
        
        ptr = new_head;
        while (ptr -> next) {
            ptr = ptr -> next;
        }
        ptr -> next = head;
        return new_head;
    }
private:
    int length(ListNode *head)
    {
        int len = 0;
        while (head) {
            head = head -> next;
            len++;
        }
        return len;
    }
};

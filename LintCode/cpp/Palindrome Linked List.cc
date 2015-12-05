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
     * @param head a ListNode
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }
        ListNode* ptr = head;
        return dfs(head, ptr);
    }
private:
    bool dfs(ListNode* cur, ListNode* &ptr) {
        bool res = true;
        if (cur->next != nullptr) {
            res = dfs(cur->next, ptr);
        }
        if (!res) {
            return false;
        }
        res = ptr->val == cur->val;
        ptr = ptr->next;
        return res;
    }
};

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        _head = head; 
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int cnt = 0;
        int res = -1;
        for (auto cur = _head; cur != nullptr; cur = cur->next) {
            cnt++;
            if (roll(cnt)) {
                res = cur->val;
            }
        }
        return res;
    }
private:
    bool roll(int cnt) {
        int x = random() % cnt;
        return x == 0;
    }
private:
    ListNode* _head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

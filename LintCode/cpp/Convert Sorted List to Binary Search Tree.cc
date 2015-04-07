/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre_slow = nullptr;
        
        move_two_pointers(fast, slow, pre_slow);
        
        if (pre_slow == nullptr || slow->next == nullptr) {
            TreeNode* root = new TreeNode(head->val);
            root->right = sortedListToBST(head->next);
            return root;
        }
        
        pre_slow->next = NULL;
        
        ListNode* left = head;
        ListNode* right = slow->next;
        ListNode* pivot = slow;
        
        TreeNode* root = new TreeNode(pivot->val);
        root->left  = sortedListToBST(left);
        root->right = sortedListToBST(right);
        
        return root;
    }
private:
    void move_two_pointers(ListNode* &fast, ListNode* &slow, ListNode* &pre_slow) {
        while (fast) {
            if (fast) {
                fast = fast->next;
            }
            if (fast) {
                fast = fast->next;
            } else {
                break;
            }
            
            pre_slow = slow;
            slow = slow->next;
        }
    }
};




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) {
            return NULL;
        }
        return sortedListToBST(head, NULL);
    }
private:
    TreeNode *sortedListToBST(ListNode *begin, ListNode *end) {
        if (begin == end) {
            return NULL;
        }
        ListNode *mid = get_mid(begin, end);
        TreeNode *root = new TreeNode(mid -> val);
        root -> left = sortedListToBST(begin, mid);
        root -> right = sortedListToBST(mid -> next, end);
        return root;
    }
    
    ListNode *get_mid(ListNode *begin, ListNode *end) {
        if (begin == end) {
            return NULL;
        }
        ListNode *a, *b;
        a = b = begin;
        while (true) {
            if (b -> next == end) {
                break;
            }
            b = b -> next;

            if (b -> next == end) {
                break;
            }
            b = b -> next;
            
            if (a -> next == end) {
                break;
            }
            a = a -> next;
        }
        return a;
    }
};

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }
        if (!root -> left && !root -> right) {
            return;
        }
        // --
        if (root -> left && root -> right) {
            root -> left -> next = root -> right;
        }

        TreeLinkNode *parent_next = root -> next;
        TreeLinkNode *child_next = NULL;
        while (parent_next && !child_next) {
            if (parent_next -> left) {
                child_next = parent_next -> left;
            } else if (parent_next-> right) {
                child_next = parent_next -> right;
            }
            
            parent_next = parent_next -> next;
        }
        if (root -> right) {
            root -> right -> next = child_next;
        } else if (root -> left) {
            root -> left -> next = child_next;
        }
        if (root -> right) {
            connect(root -> right);
        }
        if (root -> left) {
            connect(root -> left);
        }
    }
};

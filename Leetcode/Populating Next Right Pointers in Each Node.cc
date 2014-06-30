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
        do_connect(root);
    }
    
    void do_connect(TreeLinkNode *root) {
        if (root -> left && root -> right) {
            root -> left -> next = root -> right;
        }
        if (root -> next && root -> right) {
            root -> right -> next = root -> next -> left;
        }
        if (root -> left) {
            do_connect(root -> left);
        }
        if (root -> right) {
            do_connect(root -> right);
        }
    }
};

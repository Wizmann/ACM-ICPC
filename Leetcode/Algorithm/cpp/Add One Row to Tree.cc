/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* cur = new TreeNode(v);
            cur->left = root;
            return cur;
        }
        do_add(root, v, d - 1);
        return root;
    }
private:
    void do_add(TreeNode* cur, int v, int d) {
        if (cur == nullptr) {
            return;
        }
        if (d == 1) {
            {
                TreeNode* lc = new TreeNode(v);
                lc->left = cur->left;
                cur->left = lc;
            }
            {
                TreeNode* rc = new TreeNode(v);
                rc->right = cur->right;
                cur->right = rc;
            }
            return;
        }
        do_add(cur->left, v, d - 1);
        do_add(cur->right, v, d - 1);
    }
};

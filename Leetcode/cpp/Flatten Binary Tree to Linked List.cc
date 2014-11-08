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
    void flatten(TreeNode *root) {
        if (!root) return;
        if (root -> left) {
            TreeNode* tn = rightmost(root -> left);
            tn -> right = root -> right;
            root -> right = root -> left;
            root -> left = NULL;
        }
        flatten(root -> right);
    }
    TreeNode* rightmost(TreeNode* root) {
        while (root && root -> right) {
            root = root -> right;
        }
        return root;
    }
};

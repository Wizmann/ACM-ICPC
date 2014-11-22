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
    TreeNode* flatten(TreeNode *root) {
        if (!root) {
            return root;
        }
        TreeNode* left_rightmost = flatten(root->left);
        
        if (left_rightmost) {
            left_rightmost->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        if (root->right) {
            return flatten(root->right);
        } else {
            return root;
        }
    }
};

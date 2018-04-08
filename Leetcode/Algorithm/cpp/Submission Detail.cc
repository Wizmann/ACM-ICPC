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
    TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        
        if (root->left == nullptr && root->right == nullptr && root->val == 0) {
            return nullptr;
        }
        
        return root;
    }
};

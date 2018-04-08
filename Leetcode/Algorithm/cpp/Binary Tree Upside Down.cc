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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == nullptr || root->left == nullptr) {
            return root;
        }
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        TreeNode* newroot = upsideDownBinaryTree(root->left);
        left->right = root;
        left->left = right;
        root->left = root->right = nullptr;
        return newroot;
    }
};

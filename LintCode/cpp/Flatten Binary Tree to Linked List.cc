/**
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr) {
            flatten(root->right);
            return;
        }
        TreeNode* lr = right_most(root->left);
        lr->right = root->right;
        root->right = root->left;
        root->left = nullptr;
        flatten(root->right);
    }
private:
    TreeNode* right_most(TreeNode* root) {
        TreeNode* ptr = root;
        while (ptr->right) {
            ptr = ptr->right;
        }
        return ptr;
    }
};

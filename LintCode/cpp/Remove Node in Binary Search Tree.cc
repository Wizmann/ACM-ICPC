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
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode fake_root(numeric_limits<int>::max());
        fake_root.left = root;
        
        TreeNode** pre = nullptr;
        TreeNode* cur = &fake_root;
        
        while (cur && cur->val != value) {
            if (value < cur->val) {
                pre = &(cur->left);
                cur = cur->left;
            }  else {
                pre = &(cur->right);
                cur = cur->right;
            }
        }
        
        if (cur == nullptr) {
            return root;
        }

        *pre = do_remove(cur);
        return fake_root.left;
    }
private:
    TreeNode* do_remove(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        if (root->left) {
            auto cur = root->left;
            while (cur->right) {
                cur = cur->right;
            }
            cur->right = root->right;
            auto res = root->left;
            delete root;
            return res;
        } else {
            auto res = root->right;
            delete root;
            return res;
        }
    }
};

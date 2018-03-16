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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }
        TreeNode dummy_root(-1);
        dummy_root.left = root;
        do_delete(&(dummy_root.left), root, key);
        return dummy_root.left;
    }
private:
    void do_delete(TreeNode** pre, TreeNode* root, int key) {
        if (root == nullptr) {
            return;
        }
        if (root->val > key) {
            do_delete(&(root->left), root->left, key);
        } else if (root->val < key) {
            do_delete(&(root->right), root->right, key);
        } else {
            *pre = delete_node(root);
        }
    }
    
    TreeNode* delete_node(TreeNode* root) {
        if (root->left == nullptr) {
            return root->right;
        }
        TreeNode* cur = root->left;
        while (cur->right != nullptr) {
            cur = cur->right;
        }
        cur->right = root->right;
        return root->left;
    }
};

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
        return do_delete(root, key);
    }
private:
    TreeNode* do_delete(TreeNode* cur, int key) {
        if (cur == nullptr) {
            return nullptr;
        }
        int val = cur->val;
        if (val > key) {
            cur->left = do_delete(cur->left, key);
            return cur;
        } else if(val < key) {
            cur->right = do_delete(cur->right, key);
            return cur;
        }
        
        if (cur->right == nullptr) {
            return cur->left;
        } else if(cur->left == nullptr) {
            return cur->right;
        }
        
        TreeNode* left_maxi = find_max(cur->left);
        if (left_maxi == cur->left) {
            cur->left->right = cur->right;
            return cur->left;
        }
        cur->val = left_maxi->val;
        do_delete(cur->left, cur->val);
        return cur;
    }
    
    TreeNode* find_max(TreeNode* cur) {
        if (cur == nullptr) {
            return nullptr;
        }
        if (cur->right) {
            return find_max(cur->right);
        } else {
            return cur;
        }
    }
};

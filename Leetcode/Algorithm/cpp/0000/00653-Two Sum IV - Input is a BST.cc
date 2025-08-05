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
    bool findTarget(TreeNode* root, int k) {
        return dfs1(root, root, k);
    }
private:
    bool dfs1(TreeNode* cur, TreeNode* root, int k) {
        if (cur == nullptr) {
            return false;
        }
        if (dfs2(cur, root, k)) {
            return true;
        }
        return dfs1(cur->left, root, k) || dfs1(cur->right, root, k);
    }
    
    bool dfs2(TreeNode* cur, TreeNode* next, int k) {
        if (cur == nullptr) {
            return false;
        }
        if (next == nullptr) {
            return false;
        }
        
        if (cur->val + next->val == k && cur != next) {
            return true;
        }
        if (cur->val + next->val >= k) {
            return dfs2(cur, next->left, k);
        } else {
            return dfs2(cur, next->right, k);
        }
    }
};

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
    int kthSmallest(TreeNode* root, int k) {
        res = 0;
        dfs(root, k);
        return res;
    }
private:
    int dfs(TreeNode* cur, int k) {
        if (cur == nullptr) {
            return 0;
        }
        int l_size = dfs(cur->left, k);
        if (l_size == k - 1) {
            res = cur->val;
        }
        int r_size = dfs(cur->right, k - 1 - l_size);
        return l_size + r_size + 1;
    }
private:
    int res;
};

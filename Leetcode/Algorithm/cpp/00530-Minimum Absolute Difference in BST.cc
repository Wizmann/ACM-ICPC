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
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) {
            return -1;
        }
        res = numeric_limits<int>::max();
        pre = nullptr;
        dfs(root);
        return res;
    }
private:
    void dfs(TreeNode* cur) {
        if (cur == nullptr) {
            return;
        }
        dfs(cur->left);
        if (pre) {
            res = min(res, abs(cur->val - pre->val));
        }
        pre = cur;
        dfs(cur->right);
    }

    int res;
    TreeNode* pre;
};

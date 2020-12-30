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
    int rangeSumBST(TreeNode* root, int L, int R) {
        sum = 0;
        dfs(root, L, R);
        return sum;
    }
    
    void dfs(TreeNode* root, int l, int r) {
        if (root == nullptr) {
            return;
        }
        if (l <= root->val && root->val <= r) {
            sum += root->val;
        }
        
        if (l <= root->val) {
            dfs(root->left, l, r);
        }
        
        if (root->val <= r) {
            dfs(root->right, l, r);
        }
    }
private:
    int sum;
};

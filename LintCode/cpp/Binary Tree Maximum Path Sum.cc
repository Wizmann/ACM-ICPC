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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        ans = numeric_limits<int>::min();
        do_maxPathSum(root);
        return ans;
    }
private:
    int do_maxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = max(0,
            do_maxPathSum(root->left));
        int right = max(0,
            do_maxPathSum(root->right));
        ans = max(ans, root->val + left + right);
        return root->val + max(left, right);
    }
private:
    int ans;
};

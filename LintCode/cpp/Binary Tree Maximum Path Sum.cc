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
        if (!root) {
            return 0;
        }
        ans = -0x3f3f3f3f;
        do_maxPathSum(root);
        return ans;
    }
private:
    int do_maxPathSum(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int l_value = max(0, do_maxPathSum(root->left));
        int r_value = max(0, do_maxPathSum(root->right));
        ans = max(ans, l_value + r_value + root->val);

        return max(l_value, r_value) + root->val;
    }
private:
    int ans;
};


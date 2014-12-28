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
        ans = -INF;
        _maxPathSum(root);
        return ans;
    }
private:
    static const int INF = 0x3f3f3f3f;
    int ans;
private:
    int _maxPathSum(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left =  max(0, _maxPathSum(root->left));
        int right = max(0, _maxPathSum(root->right));
        
        ans = max(ans, root->val + left + right);
        return max(root->val + left, root->val + right);
    }
};

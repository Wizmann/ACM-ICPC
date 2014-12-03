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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        _res = true;
        judge(root);
        return _res;
    }
private:
    int judge(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left  = judge(root->left);
        int right = judge(root->right);
        
        if (abs(right - left) > 1) {
            _res = false;
        }
        return max(left, right) + 1;
    }
private:
    bool _res;
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int x;
        if (!root) {
            return true;
        }
        return _isBalanced(root, x);
    }
    
    bool _isBalanced(TreeNode *root, int& depth)
    {
        int left_depth = 0;
        int right_depth = 0;
        
        bool left_bal = true;
        if (root->left) {
            left_bal = _isBalanced(root->left, left_depth);
        }
        bool right_bal = true;
        if (root->right) {
            right_bal = _isBalanced(root->right, right_depth);
        }
        
        depth = max(left_depth, right_depth) + 1;
        if (!left_bal || !right_bal) return false;
        else {
            if (abs(left_depth - right_depth) > 1) return false;
            else return true;
        }
    }
};

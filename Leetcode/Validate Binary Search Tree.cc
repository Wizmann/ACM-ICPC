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
    bool isValidBST(TreeNode *root) {
        return !root || 
                _isValidBST(root -> left, INT_MIN, root -> val) && 
                _isValidBST(root -> right, root -> val, INT_MAX);
    }
    
    bool _isValidBST(TreeNode *root, int mini, int maxi) {
        if (not root) return true;
        else if (not (mini < root -> val && root -> val < maxi)) return false;
        else return _isValidBST(root -> left, mini, root -> val) && 
                    _isValidBST(root -> right, root -> val, maxi);
    }
};

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
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return _maxDepth(root, 0);
    }
    
    int _maxDepth(TreeNode *root, int depth) {
        if (root->left == NULL && root->right == NULL) {
            return depth;
        }
        
        int res = 0;
        if (root->left) {
            res = max(res, _maxDepth(root->left, depth + 1));
        }
        if (root->right) {
            res = max(res, _maxDepth(root->right, depth + 1));
        }
        
        return res;
    }
};

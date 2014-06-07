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
        res = true;
        if (!root) {
            return true;
        }
        do_is_balanced(root);
        return res;
    }
    
    int do_is_balanced(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int l = do_is_balanced(root -> left);
        int r = do_is_balanced(root -> right);
        
        if (abs(l - r) > 1) {
            res = false;
        }
        return max(l, r) + 1;
    }
private:
    bool res;
};

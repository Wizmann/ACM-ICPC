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
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return isSymmetric(root -> left, root -> right);
    }
    
    bool isSymmetric(TreeNode *ll, TreeNode *rr) {
        if (ll == rr) {
            return true;
        }
        if (!ll || !rr)  {
            return false;
        }
        
        if (ll -> val != rr -> val) {
            return false;
        }
        
        return isSymmetric(ll -> left, rr -> right) && isSymmetric(ll -> right, rr -> left);
    }
};

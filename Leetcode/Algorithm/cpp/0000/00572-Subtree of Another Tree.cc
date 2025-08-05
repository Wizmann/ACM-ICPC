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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return solve(s, t, false);
    }
    
    bool solve(TreeNode* s, TreeNode* t, bool track) {
        if (s == nullptr && t == nullptr) {
            return true;
        }
        
        if (s == nullptr || t == nullptr) {
            return false;
        }
        
        bool flag = false;
        
        if (s->val == t->val) {
            flag |= solve(s->left, t->left, true) && solve(s->right, t->right, true);
        }
        
        if (flag) {
            return true;
        }
        
        if (track) {
            return false;
        }
        
        flag |= solve(s->left, t, false);
        
        if (flag) {
            return true;
        }
        
        flag |= solve(s->right, t, false);
        
        if (flag) {
            return true;
        }
        
        return false;
    }
};

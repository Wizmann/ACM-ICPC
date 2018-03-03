/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

const int MANY = -0x3f3f3f3f;

class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode* cur) {
        if (cur == nullptr) {
            return MANY;
        }
        int a = cur->val;
        int b = cur->val;
        
        if (cur->left) {
            a = dfs(cur->left);
        }
        
        if (cur->right) {
            b = dfs(cur->right);
        }
        
        if (a == MANY || b == MANY) {
            return MANY;
        }
        
        if (a == cur->val && b == cur->val) {
            ans++;
            return cur->val;
        }
        
        return MANY;
    }
private:
    int ans;
};

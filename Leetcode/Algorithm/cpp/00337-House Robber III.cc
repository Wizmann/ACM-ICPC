/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

const int INF = 0x3f3f3f3f;

class Solution {
public:
    int rob(TreeNode* root) {
        return do_rob(root, false);
    }
private:
    int do_rob(TreeNode* root, bool pre) {
        if (root == NULL) {
            return 0;
        }
        
        if (pre && tmp.find(root) != tmp.end()) {
            return tmp[root];
        }
        
        if (!pre && fmp.find(root) != tmp.end()) {
            return fmp[root];
        }
        
        int res = -INF;
        if (!pre) {
            res = max(res, root->val + do_rob(root->left, true) + do_rob(root->right, true));
        }
        res = max(res, do_rob(root->left, false) + do_rob(root->right, false));
        
        if (pre) {
            tmp[root] = res;
        }
        
        if (!pre) {
            fmp[root] = res;
        }
        
        return res;
    }
private:
    unordered_map<TreeNode*, int> tmp, fmp;
};

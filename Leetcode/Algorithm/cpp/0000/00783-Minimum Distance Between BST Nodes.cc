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
    int minDiffInBST(TreeNode* root) {
        mindiff = INF;
        pre = -INF;
        dfs(root);
        return mindiff;
    }
private:
    void dfs(TreeNode* root) {
        if (root->left) {
            dfs(root->left);
        }
        
        if (pre != -INF) {
            mindiff = min(mindiff, root->val - pre);
        }
        pre = root->val;
        
        if (root->right) {
            dfs(root->right);
        }
    }
    
    int mindiff;
    int pre;
};

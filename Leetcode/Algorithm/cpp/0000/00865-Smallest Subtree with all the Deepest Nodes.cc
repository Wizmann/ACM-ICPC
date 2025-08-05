/*$$$
[Tags]
dfs, tree

[Difficulty]
2

[Url]
https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/
$$$*/

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        maxi = -1;
        res = nullptr;
        dfs(root, 1);
        return res;
    }
    
    int dfs(TreeNode* root, int depth) {
        if (root == nullptr) {
            return -1;
        }
        
        int a = dfs(root->left, depth + 1);
        int b = dfs(root->right, depth + 1);
        
        int c = max(a, b);
        
        if (c == -1) {
            if (depth > maxi) {
                res = root;
                maxi = depth;
            }
            return depth;
        } else if (a == b) {
            if (c >= maxi) {
                res = root;
                maxi = c;
            }
            return c;
        } else {
            return c;
        }
    }
private:
    TreeNode* res;
    int maxi;
};

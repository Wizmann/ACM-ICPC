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
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        if (target > root->val && root->right) {
            int u = closestValue(root->right, target);
            if (abs(target - u) < abs(target - res)) {
                res = u;
            }
        } else if (target < root->val && root->left) {
            int u = closestValue(root->left, target);
            if (abs(target - u) < abs(target - res)) {
                res = u;
            }
        }

        return res;
    }
};

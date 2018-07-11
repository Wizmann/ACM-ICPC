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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k_) {
        k = k_;
        dfs(root, target, INF);
        return res;
    }

    int dfs(TreeNode* cur, TreeNode* target, int dis) {
        if (cur == nullptr) {
            return dis;
        }

        if (cur == target) {
            dis = 0;
        }

        int l = dfs(cur->left, target, dis + 1);
        if (dis >= INF && l < INF) {
            dis = l + 1;
        }
        int r = dfs(cur->right, target, dis + 1);
        if (dis >= INF && r < INF) {
            dis = r + 1;
            dfs(cur->left, target, dis + 1);
        }

        if (dis == k) {
            res.push_back(cur->val);
        }
        return dis;
    }
private:
    int k;
    vector<int> res;
};

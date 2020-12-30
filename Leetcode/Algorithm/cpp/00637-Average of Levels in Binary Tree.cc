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
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root, 0);
        vector<double> result;
        for (auto p: res) {
            result.push_back(p.second);
        }
        return result;
    }
private:
    void dfs(TreeNode* cur, int depth) {
        if (cur == nullptr) {
            return;
        }
        
        if (res.size() == depth) {
            res.push_back({0, 0});
        }
        
        int val = cur->val;
        if (res[depth].first == 0) {
            res[depth] = {1, val};
        } else {
            int num = res[depth].first;
            double ave = res[depth].second;
            res[depth] = {num + 1, (ave * num + val) / (num + 1)};
        }
        
        if (cur->left) {
            dfs(cur->left, depth + 1);
        }
        if (cur->right) {
            dfs(cur->right, depth + 1);
        }
    }
private:
    vector<pair<int, double> > res;
};

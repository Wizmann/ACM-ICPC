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
    int pathSum(TreeNode* root, int sum_) {
        sum = sum_;
        ans = 0;
        psum.push_back(0);
        mp[0] = 1;
        dfs(root);
        return ans;
    }
private:
    void dfs(TreeNode* cur) {
        if (cur == nullptr) {
            return;
        }
        int u = cur->val;
        int s = *psum.rbegin();
        int ss = u + s;
        int expected = ss - sum;

        ans += mp[expected];
        
        psum.push_back(ss);
        mp[ss]++;
        
        dfs(cur->left);
        dfs(cur->right);
        
        psum.pop_back();
        mp[ss]--; 
    }
private:
    int sum;
    int ans;
    unordered_map<int, int> mp;
    vector<int> psum;
};

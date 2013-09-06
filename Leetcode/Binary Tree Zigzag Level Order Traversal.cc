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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 0));
        vector<vector<int> > res;
        while (!q.empty()) {
            pair<TreeNode*, int> now = q.front();
            q.pop();
            
            int lv = now.second;
            TreeNode* pnode = now.first;
            
            if (!pnode) {
                continue;
            }
            
            if (lv == res.size()) {
                res.push_back(vector<int>());
            }
            
            res[lv].push_back(pnode -> val);
            
            q.push(make_pair(pnode -> left, lv + 1));
            q.push(make_pair(pnode -> right, lv + 1));
        }
        for (int i = 0; i < res.size(); i++) {
            if (i & 1) {
                reverse(res[i].begin(), res[i].end());
            }
        }
        return res;
    }
};

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
        vector<vector<int> > res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q[2];
        int ptr = 0, cnt = 0;
        q[ptr].push(root);
        
        while (!q[ptr].empty()) {
            int qtr = ptr ^ 1;
            q[qtr] = queue<TreeNode*> ();
            vector<int> v;
            while (!q[ptr].empty()) {
                TreeNode *now = q[ptr].front();
                q[ptr].pop();
                v.push_back(now -> val);
                if (now -> left) {
                    q[qtr].push(now -> left);
                }
                if (now -> right) {
                    q[qtr].push(now -> right);
                }
            }
            if (cnt % 2) {
                reverse(v.begin(), v.end());
            }
            cnt++;
            ptr = qtr;
            res.push_back(v);
        }
        return res;
    }
};

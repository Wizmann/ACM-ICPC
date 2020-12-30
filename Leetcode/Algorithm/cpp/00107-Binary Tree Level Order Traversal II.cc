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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ans;
        if (!root) {
            return ans;
        }
        
        queue<TreeNode*> q[2];
        int now = 0;
        
        q[now].push(root);
        while (!q[now].empty()) {
            int next = now ^ 1;
            q[next] = queue<TreeNode*>();
            ans.push_back(vector<int>());
            vector<int>& vec = *(--ans.end());
            while (!q[now].empty()) {
                TreeNode* p = q[now].front();
                q[now].pop();
                if (p -> left) {
                    q[next].push(p -> left);
                }
                if (p -> right) {
                    q[next].push(p -> right);
                }
                
                vec.push_back(p -> val);
            }
            now = next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

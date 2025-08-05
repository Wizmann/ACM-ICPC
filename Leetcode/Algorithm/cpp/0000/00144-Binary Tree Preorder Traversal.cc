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
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode *now = root;
        
        while (now || !st.empty()) {
            if (!now) {
                now = st.top();
                st.pop();
            }
            
            while (now) {
                res.push_back(now -> val);
                st.push(now -> right);
                now = now -> left;
            }
        }
        return res;
    }
};

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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (!root) {
            return res;
        }
        TreeNode *p = root;
        while (true) {
            if (p) {
                st.push(p);
                p = p -> left;
            } else if (!st.empty()){
                p = st.top();
                st.pop();
                res.push_back(p -> val);
                p = p -> right;
            } else {
                break;
            }
        }
        return res;
    }
};

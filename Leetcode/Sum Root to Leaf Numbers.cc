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
    int sumNumbers(TreeNode *root) {
        stack<TreeNode*> st;
        if (!root) {
            return 0;
        }
        st.push(root);
        int sum = 0;
        while (!st.empty()) {
            TreeNode* now = st.top();
            st.pop();
            int v = now->val;
            
            if (now->left) {
                now->left->val += v * 10;
                st.push(now->left);
            }
            
            if (now->right) {
                now->right->val += v * 10;
                st.push(now->right);
            }
            
            if (!now->left && !now->right) {
                sum += v;
            }
        }
        return sum;
    }
};

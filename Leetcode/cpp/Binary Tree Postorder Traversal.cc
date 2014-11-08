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
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> st;
        vector<int> res;
        
        if (!root) return res;
        
        TreeNode *pre = NULL;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode *cur = st.top();
            if ( (!cur -> left && !cur -> right) ||
                    (pre && (pre == cur -> left || pre == cur -> right))) {
                res.push_back(cur -> val);
                st.pop();
                pre = cur;
            } else {
                if (cur -> right) st.push(cur -> right);
                if (cur -> left) st.push(cur -> left);
            }
        }
        return res;
    }
};

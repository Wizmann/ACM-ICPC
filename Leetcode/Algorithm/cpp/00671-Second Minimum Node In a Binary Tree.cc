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
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        if (st.size() < 2) {
            return -1;
        }
        return *(++st.begin());
    }
private:
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (root->left) {
            dfs(root->left);
        }
        st.insert(root->val);
        if (root->right) {
            dfs(root->right);
        }
    }
    
private:
    set<int> st;
};

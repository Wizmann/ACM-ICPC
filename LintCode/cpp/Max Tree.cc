/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        TreeNode *root = NULL;
        for (auto v: A) {
            root = insert(root, v);
        }
        return root;
    }
private:
    TreeNode* insert(TreeNode* root, int v) {
        TreeNode* ptr = NULL;
        TreeNode* now = new TreeNode(v);
        
        while (!st.empty()) {
            ptr = st.top();
            if (ptr->val > v) {
                now->left = ptr->right;
                ptr->right = now;
                st.push(now);
                return root;
            }
            st.pop();
        }
        now->left = ptr;
        st.push(now);
        return now;
    }
private:
    stack<TreeNode*> st;
};

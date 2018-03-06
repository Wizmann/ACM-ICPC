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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if (root == nullptr) {
            return { nullptr };
        }
        
        TreeNode* t1 = root;
        vector<TreeNode*> st;
        
        while (root && root->val != V) {
            st.push_back(root);
            if (root->val > V) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        
        if (root == nullptr) {
            return { t1 };
        }
        
        if (st.empty()) {
            TreeNode* t2 = root->right;
            root->right = nullptr;
            return { root, t2 };
        } else {
            TreeNode* t2 = *st.rbegin();
            if (root == t2->left) {
                t2->left = root->right;
            } else {
                t2->right = root->right;
            }
            root->right = nullptr;
            return { root, t1 };
        }
    }
};

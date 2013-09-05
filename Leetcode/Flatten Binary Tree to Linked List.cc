class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) return;
        TreeNode *ltail = to_left_tail(root);
        if (ltail != root) {
            TreeNode *l_rtail = to_right_tail(root->left);
            l_rtail -> right = root -> right;
            root -> right = root -> left;
            root -> left = NULL;
        }
        flatten(root -> right);
    }
    
    TreeNode* to_left_tail(TreeNode *root)
    {
        while (root -> left) {
            root = root -> left;
        }
        return root;
    }
    
    TreeNode* to_right_tail(TreeNode *root)
    {
        while (root -> right) {
            root = root -> right;
        }
        return root;
    }
};

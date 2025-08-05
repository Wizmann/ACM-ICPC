class Solution {  
public:  
    void recoverTree(TreeNode *root) {
        if (!root) {
            return;
        }
        s1 = s2 = min_node = NULL;
        do_recover(root);
        swap(s1 -> val, s2 -> val);
    }
private:
    TreeNode *s1, *s2, *min_node;
    void do_recover(TreeNode *root) {
        if (!root) {
            return;
        }
        do_recover(root -> left);
        if (min_node && min_node -> val > root -> val) {
            if (!s1) {
                s1 = min_node;
            }
            s2 = root;
        }
        min_node = root;
        do_recover(root -> right);
    }
};

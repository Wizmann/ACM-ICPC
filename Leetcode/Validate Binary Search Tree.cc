class Solution {
public:
    bool isValidBST(TreeNode *root) {
        _root = root;
        return _isValidBST(_root);
    }
    bool _isValidBST(TreeNode *root) {
        if (!root) return true;
        if (_search(root -> val, _root) == root) {
            return _isValidBST(root -> left) && _isValidBST(root -> right);
        }
        return false;
    }
    
    TreeNode* _search(int val, TreeNode* root) {
        if (!root) return false;
        
        if (root -> val > val) {
            return _search(val, root -> left);
        } else if (root -> val < val) {
            return _search(val, root -> right);
        } else {
            return root;
        }
    }
    TreeNode* _root;
};

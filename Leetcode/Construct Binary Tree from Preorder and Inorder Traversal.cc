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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int np = preorder.size();
        int ni = inorder.size();
        if (np == 0) return NULL;
        else return _buildTree(preorder, 0, np - 1, inorder, 0, ni - 1);
    }
    
    TreeNode *_buildTree(vector<int> &preorder, int pre_st, int pre_end, vector<int> &inorder, int in_st, int in_end) {
        if (pre_st > pre_end) return NULL;
        /* ------------------- */
        int root = preorder[pre_st];
        int in_root = in_st;
        for (/*pass*/; in_root <= in_end; in_root++) {
            if (inorder[in_root] == root) {
                break;
            }
        }
        int n_left = in_root - in_st;
        int n_right = in_end - in_root;
        
        TreeNode* now = new TreeNode(root);
        
        now -> left = _buildTree(preorder, pre_st + 1, pre_st + n_left, inorder, in_st, in_root - 1);
        now -> right = _buildTree(preorder, pre_st + n_left + 1, pre_end, inorder, in_root + 1, in_end);
        return now;
    }
};

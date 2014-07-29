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
    TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder) {
        _inorder = inorder;
        _postorder = postorder;
        mp.clear();
        
        int n = inorder.size();
        if (n == 0) {
            return NULL;
        }
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        
        return do_build_tree(0, n - 1, 0, n - 1);
    }
private:
    TreeNode *do_build_tree(int ist, int iend, int pst, int pend)
    {
        int v = _postorder[pend];
        TreeNode *root = new TreeNode(v);
        int p = mp[v];
        int lnum = p - ist;
        int rnum = iend - p;
        if (lnum) root -> left = do_build_tree(ist, p - 1, pst, pst + lnum - 1);
        if (rnum) root -> right = do_build_tree(p + 1, iend, pend - rnum, pend - 1);
        return root;
    }
private:
    vector<int> _inorder, _postorder;
    map<int, int> mp;
};

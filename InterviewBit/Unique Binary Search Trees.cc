/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<TreeNode*> do_generateTrees(int l, int r) {
    if (l > r) {
        return { nullptr };
    }
    vector<TreeNode*> res;
    
    for (int i = l; i <= r; i++) {
        vector<TreeNode*> lsub = do_generateTrees(l, i - 1);
        vector<TreeNode*> rsub = do_generateTrees(i + 1, r);
        
        for (auto l: lsub) {
            for (auto r: rsub) {
                TreeNode* cur = new TreeNode(i);
                cur->left = l;
                cur->right = r;
                
                res.push_back(cur);
            }
        }
    }
    return res;
} 

vector<TreeNode*> Solution::generateTrees(int A) {
    return do_generateTrees(1, A);
    
}

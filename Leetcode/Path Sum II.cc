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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> t;
        _pathSum(root, sum, t, res);
        return res;
    }
    
    void _pathSum(TreeNode *root, int sum, vector<int>& t, vector<vector<int> > &res)
    {
        if (!root) return;
        
        sum -= root -> val;
        t.push_back(root -> val);
        if (root -> left == NULL &&
                root -> right == NULL &&
                sum == 0) {
            res.push_back(t);
        } else {
            _pathSum(root -> left, sum, t, res);
            _pathSum(root -> right, sum, t, res);
        }
        t.pop_back();
    }
};

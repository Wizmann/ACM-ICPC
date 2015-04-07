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
    vector<int> rightSideView(TreeNode *root) {
        res.clear();
        traverse(root, 1);
        return res;
    }
private:
    void traverse(TreeNode* root, int depth) {
        if (!root) {
            return;
        }
        if (depth > static_cast<int>(res.size())) {
            res.push_back(root->val);
        }
        traverse(root->right, depth + 1);
        traverse(root->left,  depth + 1);
    }
private:
    vector<int> res;
};

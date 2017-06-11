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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return nullptr;
        } else  {
            TreeNode* cur = new TreeNode( (t1? t1->val: 0) + (t2? t2->val: 0) );
            cur->left = mergeTrees(t1? t1->left: nullptr, t2? t2->left: nullptr);
            cur->right = mergeTrees(t1? t1->right: nullptr, t2? t2->right: nullptr);
            return cur;
        }
    }
};

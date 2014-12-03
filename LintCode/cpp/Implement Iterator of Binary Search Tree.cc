/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution {
public:
    // @param root: The root of binary tree.
    Solution(TreeNode *root): _root(root), _cur(root) {
        // pass
    }

    // @return: True if there has next node, or false
    bool hasNext() {
        return _cur || !_st.empty();
    }

    // @return: return next node
    TreeNode* next() {
        TreeNode *res = NULL;
        if (!_cur) {
            _cur = _st.top();
            _st.pop();
            res = _cur;
            _cur = _cur->right;
        } else {
            while (_cur) {
                _st.push(_cur);
                _cur = _cur->left;
            }
            _cur = _st.top();
            _st.pop();
            res = _cur;
            _cur = _cur->right;
        }
        return res;
    }

private:
    TreeNode *_root;
    TreeNode *_cur;
    stack<TreeNode*> _st;
};

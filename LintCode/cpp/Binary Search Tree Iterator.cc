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
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        cur = root;
        st = stack<TreeNode*>();
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        return cur || !st.empty();
    }
    
    //@return: return next node
    TreeNode* next() {
        while (cur || !st.empty()) {
            if (!cur) {
                cur = st.top();
                st.pop();
                auto res = cur;
                cur = cur->right;
                return res;
            } else {
                while (cur) {
                    st.push(cur);
                    cur = cur->left;
                }
            }
        }
        return nullptr;
    }
private:
    TreeNode* cur;
    stack<TreeNode*> st;
};

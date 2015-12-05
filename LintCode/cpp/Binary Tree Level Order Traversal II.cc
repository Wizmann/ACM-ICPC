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
 */
 
 
class Solution {
    /**
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        bool flag = true;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            
            if (node == nullptr) {
                flag = true;
                if (q.front()) {
                    q.push(nullptr);
                }
                continue;
            }
            
            if (flag) {
                res.push_back({});
            }
            flag = false;
            res.rbegin()->push_back(node->val);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

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
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int> > res(1);
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            if (cur == nullptr) {
                if (!q.empty()) {
                    q.push(nullptr);
                    res.push_back({});
                }
                continue;
            }
            
            res.rbegin()->push_back(cur->val);
            
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
        int n = res.size();
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                reverse(res[i].begin(), res[i].end());
            }
        }
        
        return res;
    }
};

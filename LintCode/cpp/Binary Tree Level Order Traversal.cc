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
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        res.clear();
        if (root != nullptr) {
            _levelOrder(root);
        }
        return res;
    }
private:
    void _levelOrder(TreeNode *root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        vector<int> cur_level;
        while (!q.empty()) {
            auto ptr = q.front();
            q.pop();
            
            if (ptr == nullptr) {
                res.push_back(cur_level);
                cur_level.clear();
                if (!q.empty()) {
                    q.push(nullptr);
                }
                continue;
            }
            
            if (ptr->left) {
                q.push(ptr->left);
            }
            if (ptr->right) {
                q.push(ptr->right);
            }
            cur_level.push_back(ptr->val);
        }
    }
private:
    vector<vector<int> > res;
};


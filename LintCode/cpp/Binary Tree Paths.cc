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
public:
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        res.clear();
        path.clear();
        if (!root) {
            return res;
        }
        dfs(root);
        return res;
    }
private:
    void dfs(TreeNode* cur) {
        if (cur == nullptr) {
            string path_str;
            for (auto node: path) {
                if (!path_str.empty()) {
                    path_str += "->";
                }
                path_str += to_string(node);
            }
            res.push_back(path_str);
            return;
        }
        path.push_back(cur->val);
        if (!cur->left && !cur->right) {
            dfs(nullptr);
        } else if (cur->left && cur->right) {
            dfs(cur->left);
            dfs(cur->right);
        } else if (cur->left) {
            dfs(cur->left);
        } else {
            dfs(cur->right);
        }
        path.pop_back();
    }
private:
    vector<string> res;
    vector<int> path;
};

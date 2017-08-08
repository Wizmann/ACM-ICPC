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
    vector<vector<string>> printTree(TreeNode* root) {
        int depth = get_depth(root);
        if (depth == 0) {
            return vector<vector<string> >();
        }
        cout << depth << endl;
        res.clear();
        for (int i = 0; i < depth; i++) {
            res.push_back(vector<string>((1 << depth) - 1, ""));
        }
        dfs(root, ((1 << depth) - 1) / 2, 0, 1 << (depth - 2));
        return res;
    }
private:
    int get_depth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + max(get_depth(root->left), get_depth(root->right));
    }
    void dfs(TreeNode* root, int x, int y, int offset) {
        if (root == nullptr) {
            return;
        }
        res[y][x] = to_string(root->val);
        dfs(root->left, x - offset, y + 1, offset >> 1);
        dfs(root->right, x + offset, y + 1, offset >> 1);
    }
private:
    vector<vector<string> > res;
};

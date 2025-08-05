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
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int a = depthRight(root->left);
        int b = depthRight(root->right);
        
        if (a == b) {
            return (1 << b) + countNodes(root->left);
        } else if (a > b) {
            return (1 << a) + countNodes(root->right);
        }
    }
private:
    int depthRight(TreeNode* root) {
        int res = 0;
        while (root) {
            res++;
            root = root->right;
        }
        return res;
    }
};

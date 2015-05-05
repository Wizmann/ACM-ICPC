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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return minDepth(root, 1);
    }
private:
    int minDepth(TreeNode *root, int depth) {
        if (!root->left && !root->right) {
            return depth;
        }
        int ll = root->left?  minDepth(root->left,  depth + 1): INF;
        int rr = root->right? minDepth(root->right, depth + 1): INF;
        return min(ll, rr);
    }
private:
    static const int INF = 0x3f3f3f3f;
};

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
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        if (!root) {
            return NULL;
        }
        if (root == A || root == B) {
            return root;
        }
        auto L = lowestCommonAncestor(root->left, A, B);
        auto R = lowestCommonAncestor(root->right, A, B);
        if (L && R) {
            return root;
        }
        return L? L: R;
    }
};

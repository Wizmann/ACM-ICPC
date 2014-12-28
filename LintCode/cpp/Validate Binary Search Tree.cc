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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        if (!root) {
            return true;
        }
        
        int mini, maxi;
        return do_validate(root, mini, maxi);
    }
private:
    bool do_validate(TreeNode *root, int& mini, int& maxi) {
        mini = maxi = root->val;
        if (root->left) {
            int left_mini, left_maxi;
            bool left_v  = do_validate(root->left, left_mini, left_maxi);
            if (!left_v || left_maxi >= root->val) {
                return false;
            }
            mini = left_mini;
        }
        if (root->right) {
            int right_mini, right_maxi;
            bool right_v = do_validate(root->right, right_mini, right_maxi);
            if (!right_v || right_mini <= root->val) {
                return false;
            }
            maxi = right_maxi;
        }
        return true;
    }
};

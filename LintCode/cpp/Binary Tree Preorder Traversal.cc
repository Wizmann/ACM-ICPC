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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        vector<int> res;
        
        while (cur) {
            if (cur->left == nullptr) {
                res.push_back(cur->val);
                cur = cur->right;
                continue;
            }
            
            prev = cur->left;
            while (prev->right && prev->right != cur) {
                prev = prev->right;
            }
            
            if (prev->right == nullptr) {
                res.push_back(cur->val);
                prev->right = cur;
                cur = cur->left;
            } else {
                cur = prev->right;
                prev->right = nullptr;
                cur = cur->right;
            }
        }
        return res;
    }
};


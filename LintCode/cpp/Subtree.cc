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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        if (T2 == nullptr) {
            return true;
        }
        return _isSubtree(T1, T2);
    }
    
    bool _isSubtree(TreeNode *T1, TreeNode *T2) {
        if (T1 && do_isSubtree(T1, T2)) {
            return true;
        }
        if (T1) {
            return isSubtree(T1->left, T2) ||
                   isSubtree(T1->right, T2);
        }
        return false;
    }
        
    bool do_isSubtree(TreeNode *T1, TreeNode *T2) {   
        if (T1 == nullptr && T2 == nullptr) {
            return true;
        } else if (T1 == nullptr || T2 == nullptr) {
            return false;
        }
        
        if (T1->val == T2->val) {
            return do_isSubtree(T1->left, T2->left) &&
                   do_isSubtree(T1->right, T2->right);
        }
        return false;
    }
};

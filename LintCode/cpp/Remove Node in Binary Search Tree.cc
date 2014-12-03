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
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        if (!root) {
            return NULL;
        }
        TreeNode *p = find_node(root, value);
        if (!p) {
            return root;
        }
        TreeNode *left  = p->left;
        TreeNode *right = p->right;
        if (p == root) {
            root = left? left: right;
        }
        if (left && root != left) {
            insert_node(root, left);
        }
        if (right && root != right) {
            insert_node(root, right);
        }
        return root;
    }
private:
    TreeNode* find_node(TreeNode* root, int value) {
        if (!root) {
            return NULL;
        }
        if (root->val == value) {
            return root;
        }
        if (root->left) {
            if (root->left->val == value) {
                TreeNode *res = root->left;
                root->left = NULL;
                return res;
            } else if (root->val > value) {
                return find_node(root->left, value);
            }
        }
        
        if (root->right) {
            if (root->right->val == value) {
                TreeNode *res = root->right;
                root->right = NULL;
                return res;
            } else if (root->val < value) {
                return find_node(root->right, value);
            }
        }
        return NULL;
    }
    
    void insert_node(TreeNode* root, TreeNode* node) {
        if (!root) {
            return;
        }
        if (node->val < root->val) {
            if (!root->left) {
                root->left = node;
            } else {
                insert_node(root->left, node);
            }
        } else {
            if (!root->right) {
                root->right = node;
            } else {
                insert_node(root->right, node);
            }
        }
    }
};

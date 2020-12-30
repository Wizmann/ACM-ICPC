/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return isSymmetric(root -> left, root -> right);
    }
    
    bool isSymmetric(TreeNode *ll, TreeNode *rr) {
        if (ll == rr) {
            return true;
        }
        if (!ll || !rr)  {
            return false;
        }
        
        if (ll -> val != rr -> val) {
            return false;
        }
        
        return isSymmetric(ll -> left, rr -> right) && isSymmetric(ll -> right, rr -> left);
    }
};

// ---

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        stack<TreeNode*> ll, rr;
        ll.push(root -> left);
        rr.push(root -> right);
        while (true) {
            if (ll.empty() && rr.empty()) {
                break;
            }
            TreeNode *lp = ll.top();
            ll.pop();
            TreeNode *rp = rr.top();
            rr.pop();
            
            if (!lp && !rp) {
                continue;
            }
            if (!lp || !rp) {
                return false;
            }
            if (lp -> val != rp -> val) {
                return false;
            }
            ll.push(lp -> left);
            ll.push(lp -> right);
            rr.push(rp -> right);
            rr.push(rp -> left);
        }
        return true;
    }
};

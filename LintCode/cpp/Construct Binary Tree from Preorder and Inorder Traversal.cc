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
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        if (n == 0) {
            return nullptr;
        }
        
        for (int i = 0; i < n; i++) {
            _mp[inorder[i]] = i;
        }
        
        return _buildTree(preorder, 0, n - 1, inorder, 0, n - 1);
    }
private:
    TreeNode *_buildTree(
        const vector<int> &preorder, 
        int pi, int pj,
        const vector<int> &inorder,
        int ii, int ij
    ) {
        if (pi > pj) {
            return nullptr;
        }
        int root_i = preorder[pi];
        auto root = new TreeNode(root_i);
        
        if (pi == pj) {
            return root;
        }
        
        int pivot = _mp[root_i];
        int left_s = pivot - ii;
        int right_s = ij - pivot;
        root->left = _buildTree(
            preorder, pi + 1, pi + left_s,
            inorder, ii, pivot - 1);
        root->right = _buildTree(
            preorder, pi + left_s + 1, pj,
            inorder, pivot + 1, ij);
        return root;
    }
private:
    unordered_map<int, int> _mp;
};

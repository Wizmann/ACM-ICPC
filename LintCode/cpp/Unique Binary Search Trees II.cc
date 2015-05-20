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
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
private:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode*> generateTrees(int st, int end) {
        if (st > end) {
            return {nullptr};
        }
        if (st == end) {
            return {new TreeNode(st)};
        }
        vector<TreeNode *> res;
        
        for (int i = st; i <= end; i++) {
            auto left_vec = generateTrees(st, i - 1);
            auto right_vec = generateTrees(i + 1, end);
            
            for (auto left_tree: left_vec) {
                for (auto right_tree: right_vec) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left_tree;
                    root->right = right_tree;
                    
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

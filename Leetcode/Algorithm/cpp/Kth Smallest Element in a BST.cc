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
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        do_kthSmallest(root, k, res);
        return res;
    }
private:
    int do_kthSmallest(TreeNode* root, int k, int& res) {
        if (root == nullptr) {
            return 0;
        }
        res = INF;
        int left_cnt = do_kthSmallest(root->left, k, res);
        
        if (res != INF) {
            return -1;
        }
        
        if (k - left_cnt == 1) {
            res = root->val;
            return -1;
        }
        
        int right_cnt = do_kthSmallest(root->right, k - left_cnt - 1, res);
        
        if (res != INF) {
            return -1;
        }
        
        return left_cnt + right_cnt + 1;
    }
private:
    static const int INF = numeric_limits<int>::max();
};

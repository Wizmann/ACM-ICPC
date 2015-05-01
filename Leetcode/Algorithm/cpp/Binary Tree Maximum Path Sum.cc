class Solution 
{
public:
    Solution(){}
    int maxPathSum(TreeNode *root) 
    {
        ans = -INF;
        _maxPathSum(root);
        return ans;
    }
private:
    int _maxPathSum(TreeNode *root) 
    {
        if(!root) return 0;
        int left_sum = _maxPathSum(root->left);
        int right_sum = _maxPathSum(root->right);
        ans = max(ans, left_sum + right_sum + root->val);
        return max(0, root->val + max(left_sum, right_sum))
    }
    const int INF = 1<<28;
    int ans;
};
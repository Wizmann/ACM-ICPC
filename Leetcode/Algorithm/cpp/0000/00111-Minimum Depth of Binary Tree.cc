class Solution {
public:
    int minDepth(TreeNode *root) 
    {
        return _minDepth(root);    
    }
private:
    const int INF = 1<<28;
    int _minDepth(TreeNode *root, int res=0)
    {
        if(!root) return 0;
        if(!root->left && !root->right) return res+1;
        else
        {
            int ans = INF;
            if(root->left) ans = min(ans, _minDepth(root->left, res+1));
            if(root->right) ans = min(ans, _minDepth(root->right, res+1));
            return ans;
        }
    }
};
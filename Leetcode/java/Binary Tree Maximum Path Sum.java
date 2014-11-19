/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int maxPathSum(TreeNode root) {
        ans = -0x3f3f3f3f;
        do_maxPathSum(root);
        return ans;
    }
    
    private int do_maxPathSum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int max_left  = Math.max(do_maxPathSum(root.left), 0);
        int max_right = Math.max(do_maxPathSum(root.right), 0);
        ans = Math.max(ans, max_left + root.val + max_right);
        return root.val + Math.max(max_left, max_right);
    }
    
    private int ans;
} 

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
    public List<Integer> preorderTraversal(TreeNode root) {
        TreeNode cur = root;
        TreeNode prev = null;
        
        List<Integer> res = new ArrayList<Integer>();
        
        while (cur != null) {
            if (cur.left == null) {
                res.add(cur.val);
                cur = cur.right;
                continue;
            }
            
            prev = cur.left;
            while (prev.right != null && prev.right != cur) {
                prev = prev.right;
            }
            
            if (prev.right == null) {
                res.add(cur.val);
                prev.right = cur;
                cur = cur.left;
            } else {
                cur = prev.right;
                cur = cur.right;
                prev.right = null;
            }
        }
        return res;
    }
}

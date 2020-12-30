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
    public List<Integer> inorderTraversal(TreeNode root) {
        res = new ArrayList<Integer>();
        do_inorderTraversal(root);
        return res;
    }
    
    private void do_inorderTraversal(TreeNode root) {
        if (root == null) {
            return;
        }
        if (root.left != null) {
            do_inorderTraversal(root.left);
        }
        res.add(root.val);
        if (root.right != null) {
            do_inorderTraversal(root.right);
        }
    }
    private List<Integer> res;
}
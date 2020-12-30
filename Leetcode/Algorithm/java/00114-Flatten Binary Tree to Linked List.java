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
    public TreeNode flatten(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode rightmost_of_left = flatten(root.left);
        
        if (rightmost_of_left != null) {
            rightmost_of_left.right = root.right;
            root.right = root.left;
            root.left = null;
        }
        if (root.right == null) {
            return root;
        } else {
            return flatten(root.right);
        }
    }
}
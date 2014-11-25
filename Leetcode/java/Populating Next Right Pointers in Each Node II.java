/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        while (root!= null) {
            do_connect(root);
            while (root != null && root.left == null && root.right == null) {
                root = root.next;
            }
            if (root == null) {
                break;
            }
            if (root.left != null) {
                root = root.left;
            } else {
                root = root.right;
            }
        }
    }
    public TreeLinkNode do_connect(TreeLinkNode root) {
        if (root == null) {
            return null;
        }
        if (root.left == null && root.right == null) {
            return do_connect(root.next);
        }
        if (root.left != null && root.right != null) {
            root.left.next = root.right;
            root.right.next = do_connect(root.next);
            return root.left;
        }
        if (root.left != null) {
            root.left.next = do_connect(root.next);
            return root.left;
        }
        if (root.right != null) {
            root.right.next = do_connect(root.next);
            return root.right;
        }
        return null;
    }
}

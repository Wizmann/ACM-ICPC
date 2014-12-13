/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */
public class Solution {
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    public TreeNode maxTree(int[] A) {
        int n = A.length;
        TreeNode root = null;
        stack = new Stack<TreeNode>();
        for (int i = 0; i < n; i++) {
            root = insert(root, A[i]);
        }
        return root;
    }
    
    private TreeNode insert(TreeNode root, int v) {
        TreeNode ptr = null;
        TreeNode now = new TreeNode(v);
        
        while (!stack.empty()) {
            ptr = stack.peek();
            if (ptr.val > v) {
                now.left = ptr.right;
                ptr.right = now;
                stack.push(now);
                return root;
            }
            stack.pop();
        }
        now.left = ptr;
        stack.push(now);
        return now;
    }
    
    private Stack<TreeNode> stack;
}
/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
 
import java.util.ArrayList;
import java.util.Collections; 

public class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        
        TreeNode dumb = new TreeNode(-1);
        dumb.left = root;
        
        TreeNode cur = dumb;
        TreeNode prev = null;
        
        while (cur != null) {
            if (cur.left == null) {
                cur = cur.right;
                continue;
            }
            
            prev = cur.left;
            while (prev.right != null && prev.right != cur) {
                prev = prev.right;
            }
            
            if (prev.right == null) {
                prev.right = cur;
                cur = cur.left;
            } else {
                res.addAll(reverse_traverse(cur.left, prev));
                prev.right = null;
                cur = cur.right;
            }
        }
        return res;
    }
    
    private List<Integer> reverse_traverse(TreeNode from, TreeNode to) {
        List<Integer> res = new ArrayList<Integer>();
        
        TreeNode cur = from;
        
        while (true) {
            res.add(cur.val);
            if (cur == to) {
                break;
            }
            cur = cur.right;
        }
        Collections.reverse(res);
        return res;
    }
}

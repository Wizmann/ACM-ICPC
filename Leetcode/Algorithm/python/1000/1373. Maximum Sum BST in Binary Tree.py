# https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

INF = 10 ** 10

class Solution:
    def maxSumBST(self, root: TreeNode) -> int:
        self.res = 0
        self.dfs(root)
        return self.res
    
    def dfs(self, cur):
        if not cur:
            return (True, 0, None, None)
        
        (l_bst, l_tot, l_min, l_max) = self.dfs(cur.left)
        (r_bst, r_tot, r_min, r_max) = self.dfs(cur.right)

        if (not l_bst) or (not r_bst) or (l_max and cur.val <= l_max) or (r_min and cur.val >= r_min):
            return (False, 0, -INF, INF)
        
        if not l_max:
            l_min = cur.val
            l_max = cur.val
        if not r_min:
            r_min = cur.val
            r_max = cur.val
        
        # print(cur.val, cur.val + l_tot + r_tot)
        self.res = max(self.res, cur.val + l_tot + r_tot)
        return (True, cur.val + l_tot + r_tot, l_min, r_max)
        
        

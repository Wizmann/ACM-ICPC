# https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def longestZigZag(self, root: TreeNode) -> int:
        self.res = 0
        self.solve(root)
        return self.res - 1
    
    def solve(self, cur):
        if not cur:
            return (0, 0)
        
        (_, l) = self.solve(cur.left)
        (r, _) = self.solve(cur.right)
        
        self.res = max(self.res, max(l, r) + 1)
        return (l + 1, r + 1)

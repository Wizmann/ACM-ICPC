# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def distributeCoins(self, root):
        self.res = 0
        self.dfs(root)
        return self.res
    
    def dfs(self, root):
        if not root:
            return (0, 0)
        
        n, m = 1, root.val
        (a, b) = self.dfs(root.left)
        n += a
        m += b
        
        (a, b) = self.dfs(root.right)
        n += a
        m += b
        
        self.res += abs(n - m)
        return n, m
            

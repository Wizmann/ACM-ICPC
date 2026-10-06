# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxAncestorDiff(self, root):
        self.ans = 0
        self.dfs(root, root.val, root.val)
        return self.ans
    
    def dfs(self, root, maxi, mini):
        if not root:
            return
        
        self.ans = max(self.ans, abs(maxi - root.val), abs(mini - root.val))
        self.dfs(root.left, max(maxi, root.val), min(mini, root.val))
        self.dfs(root.right, max(maxi, root.val), min(mini, root.val))
        

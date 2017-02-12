# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findBottomLeftValue(self, root):
        return self.findLeftMostNode(root)
        
    def findLeftMostNode(self, root):
        self.max_depth = -1
        self.res = -1
        
        self.dfs(root, 0)
        return self.res
    
    def dfs(self, root, depth):
        if not root:
            return
        
        if depth > self.max_depth:
            self.max_depth = depth
            self.res = root.val
        
        self.dfs(root.left, depth + 1)
        self.dfs(root.right, depth + 1)
        

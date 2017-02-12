# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def largestValues(self, root):
        return self.findValueMostElement(root)
    
    def findValueMostElement(self, root):
        if not root:
            return []
            
        self.d = {}
        self.max_depth = -1
        
        self.dfs(root, 0)
        res = []
        for i in xrange(self.max_depth + 1):
            res.append(self.d[i])
        return res
    
    def dfs(self, root, depth):
        if not root:
            return
        
        if depth not in self.d:
            self.d[depth] = root.val
        
        self.d[depth] = max(self.d[depth], root.val)
        self.max_depth = max(self.max_depth, depth)
        
        self.dfs(root.left, depth + 1)
        self.dfs(root.right, depth + 1)

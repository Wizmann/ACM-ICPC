# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

INF = 10 ** 10

class Solution(object):
    def findClosestLeaf(self, root, k):
        self.res = INF
        self.vertex = -1
        self.dfs(root, k)
        return self.vertex
    
    def dfs(self, root, target):
        if not root:
            return (INF, INF, INF)
        
        if not root.left and not root.right:
            if root.val == target:
                self.res = 0
                self.vertex = root.val
                return (0, 0, root.val)
            else:
                return (0, INF, root.val)
            
        (d1, k1, v1) = self.dfs(root.left, target)
        (d2, k2, v2) = self.dfs(root.right, target)
        
        k = min(k1, k2)
        
        if root.val == target:
            if self.res > d1 + 1:
                self.res = d1 + 1
                self.vertex = v1
            if self.res > d2 + 1:
                self.res = d2 + 1
                self.vertex = v2
            
            k = -1
        else:
            if self.res > d1 + k2 + 2:
                self.res = d1 + k2 + 2
                self.vertex = v1
            if self.res > d2 + k1 + 2:
                self.res = d2 + k1 + 2
                self.vertex = v2

        if d1 < d2:
            return (d1 + 1, k + 1, v1)
        else:
            return (d2 + 1, k + 1, v2) 

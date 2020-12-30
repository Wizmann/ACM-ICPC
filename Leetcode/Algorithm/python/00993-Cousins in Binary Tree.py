# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

INF = 10 ** 10

class Solution(object):
    def isCousins(self, root, x, y):
        (da, pa) = self.depth(root, -INF, x)
        (db, pb) = self.depth(root, -INF, y)
        return da == db and pa != pb
    
    def depth(self, root, parent, cur):
        if not root:
            return (-INF, -INF)
        if root.val != cur:
            (d, p) = max(
                self.depth(root.left, root.val, cur),
                self.depth(root.right, root.val, cur)
            )
            return (d + 1, p)
        else:
            return (0, parent)
        
            

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isUnivalTree(self, root):
        return self.solve(root, root.val)
    
    def solve(self, root, val):
        if not root:
            return True
        if root.val != val:
            return False
        return self.solve(root.left, val) and self.solve(root.right, val)
        

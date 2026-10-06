# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumRootToLeaf(self, root):
        return self.dfs(root, 0)
    
    def dfs(self, root, cur):
        cur = cur * 2 + root.val
        if not root.left and not root.right:
            return cur
        res = 0
        if root.left:
            res += self.dfs(root.left, cur)
        if root.right:
            res += self.dfs(root.right, cur)
        return res
        

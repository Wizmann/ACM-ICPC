# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def bstToGst(self, root):
        self.tot = 0
        self.dfs(root)
        return root
    
    def dfs(self, root):
        if not root:
            return None
        
        if root.right:
            self.dfs(root.right)
            
        self.tot += root.val
        root.val = self.tot
        
        if root.left:
            self.dfs(root.left)
            
            
    

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def smallestFromLeaf(self, root):
        return self.dfs(root)
    
    def dfs(self, root):
        if root == None:
            return ''
        
        prefix = "~"
        if root.left:
            prefix = min(prefix, self.dfs(root.left))
            
        if root.right:
            prefix = min(prefix, self.dfs(root.right))
            
        if prefix == '~':
            prefix = ''
            
        return prefix + chr(root.val + ord('a'))

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def insertIntoMaxTree(self, root, val):
        dummyRoot = TreeNode(-1)
        dummyRoot.left = self.dfs(root, val)
        return dummyRoot.left
    
    def dfs(self, root, val):
        if root == None or val > root.val:
            t = TreeNode(val)
            t.left = root
            return t
        else:
            root.right = self.dfs(root.right, val)
            return root

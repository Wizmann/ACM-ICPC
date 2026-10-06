# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def increasingBST(self, root):
        self.new_root = TreeNode(-1)
        self.cur = self.new_root
        self.dfs(root)
        return self.new_root.right
    
    def dfs(self, root):
        if not root:
            return
        if root.left:
            self.dfs(root.left)
        self.cur.right = TreeNode(root.val)
        self.cur = self.cur.right
        if root.right:
            self.dfs(root.right)

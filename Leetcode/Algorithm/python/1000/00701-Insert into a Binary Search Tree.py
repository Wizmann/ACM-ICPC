# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def insertIntoBST(self, root, val):
        if not root:
            return None
        if not root.left and val <= root.val:
            root.left = TreeNode(val)
        elif not root.right and val > root.val:
            root.right = TreeNode(val)
        elif val <= root.val:
            self.insertIntoBST(root.left, val)
        elif val > root.val:
            self.insertIntoBST(root.right, val)
        return root

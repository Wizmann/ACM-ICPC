# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return nothing, do it in place
    def flatten(self, root):
        if not root:
            return None
        rightmost_of_left = self.flatten(root.left)
        if rightmost_of_left:
           rightmost_of_left.right, root.left, root.right = root.right, None, root.left
        if root.right:
            return self.flatten(root.right)
        else:
            return root

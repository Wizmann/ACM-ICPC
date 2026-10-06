# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param num, a list of integers
    # @return a tree node
    def sortedArrayToBST(self, num):
        if not num:
            return None
        n = len(num)
        root_val = num[n / 2]
        root = TreeNode(root_val)
        root.left = self.sortedArrayToBST(num[:n / 2])
        root.right = self.sortedArrayToBST(num[n / 2 + 1:])
        return root

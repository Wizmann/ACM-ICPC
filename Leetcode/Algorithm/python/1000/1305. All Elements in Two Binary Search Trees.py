# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import heapq

class Solution(object):
    def getAllElements(self, root1, root2):
        self.nums = []
        self.traverse(root1)
        self.traverse(root2)
        return sorted(self.nums)

    def traverse(self, root):
        if not root:
            return
        self.traverse(root.left)
        self.nums.append(root.val)
        self.traverse(root.right)

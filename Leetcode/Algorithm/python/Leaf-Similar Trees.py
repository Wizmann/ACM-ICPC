# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from itertools import chain

class Solution(object):
    def leafSimilar(self, root1, root2):
        return [val for val in self.dfs(root1)] == [val for val in self.dfs(root2)]

    def dfs(self, root):
        if root and not root.left and not root.right:
            yield root.val
        elif root:
            for val in chain(self.dfs(root.left), self.dfs(root.right)):
                yield val

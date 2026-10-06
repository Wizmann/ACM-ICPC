# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import defaultdict

class Solution(object):
    def deepestLeavesSum(self, root):
        self.d = defaultdict(int)
        self.dfs(root, 0)
        key = max(self.d.keys())
        return self.d[key]

    def dfs(self, root, depth):
        if not root:
            return
        self.d[depth] += root.val
        self.dfs(root.left, depth + 1)
        self.dfs(root.right, depth + 1)
        

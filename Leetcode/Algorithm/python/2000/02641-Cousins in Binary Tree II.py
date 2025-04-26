# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import defaultdict

class Solution(object):
    def replaceValueInTree(self, root):
        self.levels = defaultdict(int)
        self.dfs1(None, root, 0)
        self.dfs2(root, 0)
        root.val = 0
        return root

    def dfs1(self, pre, cur, depth):
        if not cur:
            return
        self.levels[depth] += cur.val
        if pre:
            if pre.left == cur:
                cur.val = -cur.val - (pre.right.val if pre.right else 0)
            else:
                cur.val = -cur.val if not pre.left else pre.left.val
        self.dfs1(cur, cur.left, depth + 1)
        self.dfs1(cur, cur.right, depth + 1)

    def dfs2(self, cur, depth):
        if not cur:
            return
        cur.val += self.levels[depth]
        self.dfs2(cur.left, depth + 1)
        self.dfs2(cur.right, depth + 1)

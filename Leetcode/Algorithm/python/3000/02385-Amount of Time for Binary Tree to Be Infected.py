# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import defaultdict

class Solution(object):
    def amountOfTime(self, root, start):
        self.d = defaultdict(list)
        self.dfs1(root)
        return self.dfs2(-1, start) - 1
        
    def dfs1(self, cur):
        if cur.left:
            self.d[cur.val].append(cur.left.val)
            self.d[cur.left.val].append(cur.val)
            self.dfs1(cur.left)
            
        if cur.right:
            self.d[cur.val].append(cur.right.val)
            self.d[cur.right.val].append(cur.val)
            self.dfs1(cur.right)
            
    def dfs2(self, pre, cur):
        maxi = 0
        for nxt in self.d[cur]:
            if nxt == pre:
                continue
            maxi = max(maxi, self.dfs2(cur, nxt))
        return maxi + 1

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import defaultdict
class Solution(object):
    def verticalTraversal(self, root):
        self.d = defaultdict(list)
        self.dfs(root, 0, 0)
        res = []
        for (key, value) in sorted(self.d.items()):
            res.append(map(lambda (y, x, v): v, sorted(value)))
        return res
    
    def dfs(self, cur, y, x):
        if cur == None:
            return
        self.d[x].append((y, x, cur.val))
        if cur.left:
            self.dfs(cur.left, y + 1, x - 1)
        if cur.right:
            self.dfs(cur.right, y + 1, x + 1)
        
        

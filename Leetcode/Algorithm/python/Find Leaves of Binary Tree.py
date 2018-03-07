# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import defaultdict

class Solution(object):
    def findLeaves(self, root):
        self.d = defaultdict(list)
        
        self.dfs(root)
        return map(lambda (k, v): v, sorted(self.d.items(), key=lambda (k, v): k))
    
    def dfs(self, cur):
        if not cur:
            return -1
        
        if not cur.left and not cur.right:
            self.d[0].append(cur.val)
            return 0
        
        a = self.dfs(cur.left)
        b = self.dfs(cur.right)
        
        l = max(a + 1, b + 1)
        self.d[l].append(cur.val)
        
        return l
        

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumEvenGrandparent(self, root):
        return self.dfs(-1, -1, root)
    
    def dfs(self, gp, p, cur):
        if cur == None:
            return 0
        res = 0
        if gp % 2 == 0:
            res += cur.val
        res += self.dfs(p, cur.val, cur.left)
        res += self.dfs(p, cur.val, cur.right)
        return res

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

INF = 10 ** 10

class Solution(object):
    def longestConsecutive(self, root):
        self.res = 0
        self.dfs(INF, root, 0)
        return self.res
    
    def dfs(self, pre, cur, cnt):
        if not cur:
            self.res = max(self.res, cnt)
            return
        if pre == cur.val - 1:
            cnt += 1
            self.res = max(self.res, cnt)
        else:
            cnt = 1
            
        self.dfs(cur.val, cur.left, cnt)
        self.dfs(cur.val, cur.right, cnt)

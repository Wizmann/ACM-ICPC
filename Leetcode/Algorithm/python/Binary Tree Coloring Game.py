# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def btreeGameWinningMove(self, root, n, x):
        self.res = False
        self.xx = 0
        self.cx = []
        tot = self.dfs(root, n, x)
        #print tot, self.xx, self.cx
        if tot - self.xx > self.xx:
            return True
        u = max(self.cx)
        if u > tot - u:
            return True
        return False
    
    def dfs(self, root, n, x):
        if not root:
            return 0
        a = self.dfs(root.left, n, x)
        b = self.dfs(root.right, n, x)
        tot = 1 + a + b
        if root.val == x:
            self.cx = [a, b]
            self.xx = tot
        return tot

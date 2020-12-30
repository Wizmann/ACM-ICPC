from collections import defaultdict

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def countPairs(self, root, distance):
        self.dp = defaultdict(list)
        self.distance = distance
        res = self.dfs1(root)
        return res
    
    def dfs1(self, root):
        if not root:
            return 0
        res = 0
        for i in xrange(self.distance + 1):
            for j in xrange(0, self.distance - 2 - i + 1):
                res += self.dfs2(root.left, i) * self.dfs2(root.right, j)
        res += self.dfs1(root.left) + self.dfs1(root.right)
        return res
    
    def dfs2(self, root, distance):
        if not root:
            return 0
        if distance < 0:
            return 0
        key = (id(root), distance)
        if not root.left and not root.right and distance == 0:
            self.dp[key] = 1
            return 1
        
        if key in self.dp:
            return self.dp[key]
        tot = self.dfs2(root.left, distance - 1) + self.dfs2(root.right, distance - 1)
        self.dp[key] = tot
        return tot

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lcaDeepestLeaves(self, root):
        self.d = {}
        self.A = set()
        
        self.dfs1(root, 0)
        self.maxd = max(self.d.values())
        self.dfs2(root, [], 0)
        
        maxp = None
        maxd = -1
        for cur in self.A:
            if self.d[cur] > maxd:
                maxd = self.d[cur]
                maxp = cur
        return maxp
        
    def dfs1(self, cur, depth):
        if not cur:
            return
        self.d[cur] = depth
        self.dfs1(cur.left, depth + 1)
        self.dfs1(cur.right, depth + 1)
        
    def dfs2(self, cur, path, depth):
        if not cur:
            return
        path.append(cur)
        if depth == self.maxd:
            if not self.A:
                self.A = set(path)
            else:
                self.A &= set(path)
            path.pop()
            return
        self.dfs2(cur.left, path, depth + 1)
        self.dfs2(cur.right, path, depth + 1)
        path.pop()

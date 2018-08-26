# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.d = {}
        
    def allPossibleFBT(self, N):
        if N == 0:
            return [None]
        
        if N == 1:
            return [TreeNode(0)]
        
        if N % 2 == 0:
            return []
        
        if N in self.d:
            return self.d[N]
        
        res = []
        for i in xrange(N - 1):
            for left in self.allPossibleFBT(i):
                for right in self.allPossibleFBT(N - 1 - i):
                    cur = TreeNode(0)
                    cur.left = left
                    cur.right = right
                    
                    res.append(cur)
        self.d[N] = res
        return res

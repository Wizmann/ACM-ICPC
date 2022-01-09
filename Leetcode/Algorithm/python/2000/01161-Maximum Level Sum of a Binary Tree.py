# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

INF = 10 ** 10

class Solution(object):
    def maxLevelSum(self, root):
        s = [0]
        q = [root, None]
        ptr = 0
        while q:
            cur = q.pop(0)
            if cur is None:
                s.append(0)
                ptr += 1
                if q:
                    q.append(None)
                continue
            s[ptr] += cur.val
            if cur.left:
                q.append(cur.left)
            if cur.right:
                q.append(cur.right)
        maxi = -1
        maxv = -INF
        for key, value in enumerate(s):
            if value > maxv:
                maxv = value
                maxi = key
        return maxi + 1

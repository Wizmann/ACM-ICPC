# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import defaultdict

class Solution(object):
    def verticalOrder(self, root):
        self.d = defaultdict(list)
        self.bfs(root)
        return map(lambda (key, value): value, sorted(self.d.items(), key=lambda (k, v): k))
    
    def bfs(self, root):
        if not root:
            return
        q = [(root, 0)]
        while q:
            cur, idx = q.pop(0)
            if not cur:
                continue
                
            self.d[idx].append(cur.val)
            q.append((cur.left, idx - 1))
            q.append((cur.right, idx + 1))
        

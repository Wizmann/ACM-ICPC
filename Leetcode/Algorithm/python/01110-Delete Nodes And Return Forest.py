# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def delNodes(self, root, to_delete):
        self.to_delete = set(to_delete)
        self.res = []
        self.dfs(root, True)
        return self.res
    
    def dfs(self, cur, first):
        if not cur:
            return None
        
        if cur.val not in self.to_delete and first:
            self.res.append(cur)
        
        if cur.val in self.to_delete:
            cur.left = self.dfs(cur.left, True)
            cur.right = self.dfs(cur.right, True)
            return None
        else:
            cur.left = self.dfs(cur.left, False)
            cur.right = self.dfs(cur.right, False)
            return cur

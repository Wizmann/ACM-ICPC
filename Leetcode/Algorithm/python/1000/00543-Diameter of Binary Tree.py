# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def diameterOfBinaryTree(self, root):
        self.dia = 0
        self.dfs(root)
        return max(0, self.dia - 1)
        
    def dfs(self, cur):
        if not cur:
            return 0
            
        ll = self.dfs(cur.left)
        rr = self.dfs(cur.right)
        
        self.dia = max(self.dia, ll + rr + 1)
        
        return max(ll, rr) + 1

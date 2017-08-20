# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def checkEqualTree(self, root):
        if not root:
            return False
        
        self.tot = self.tree_sum(root)
        self.flag = False
        self.dfs(root.left)
        self.dfs(root.right)
        return self.flag
        
    def tree_sum(self, cur):
        if cur is None:
            return 0
        res = cur.val
        res += self.tree_sum(cur.left)
        res += self.tree_sum(cur.right)
        return res
    
    def dfs(self, cur):
        if cur is None:
            return 0
        res = cur.val
        res += self.dfs(cur.left)
        res += self.dfs(cur.right)
        if res * 2 == self.tot:
            self.flag = True
        return res
        

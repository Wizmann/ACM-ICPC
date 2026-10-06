# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def flipMatchVoyage(self, root, voyage):
        self.dfs1(root)
        self.res = []
        self.dfs2(root, voyage)
        return self.res
    
    def dfs1(self, root):
        if not root:
            return 0
        cur = self.dfs1(root.left) + self.dfs1(root.right)
        root.cnt = cur + 1
        return root.cnt
    
    def dfs2(self, root, voyage):
        if not root:
            return True
        num = root.cnt
        if root.val != voyage[0]:
            self.res = [-1]
            return False
        
        if root.left and root.right:
            if voyage[1] != root.left.val:
                self.res.append(root.val)
                root.left, root.right = root.right, root.left
                
            lcnt = root.left.cnt
            l = voyage[1: lcnt + 1]
            r = voyage[lcnt + 1:]

            return self.dfs2(root.left, l) and self.dfs2(root.right, r)
        else:
            return self.dfs2(root.left, voyage[1:]) and self.dfs2(root.right, voyage[1:])
        
        

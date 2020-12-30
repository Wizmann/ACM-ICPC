# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def tree2str(self, t):
        if t is None:
            return ''
        res = str(t.val)
        if t.right:
            res += '(%s)' % self.tree2str(t.left)
            res += '(%s)' % self.tree2str(t.right)
        elif t.left:
            res += '(%s)' % self.tree2str(t.left)
        
        return res

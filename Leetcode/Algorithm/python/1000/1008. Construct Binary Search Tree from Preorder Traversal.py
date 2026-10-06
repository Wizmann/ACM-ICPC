# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def bstFromPreorder(self, preorder):
        if not preorder:
            return None
        root = TreeNode(preorder[0])
        
        m = len(preorder)
        for i in xrange(1, m):
            if preorder[i] > root.val:
                root.left = self.bstFromPreorder(preorder[1: i])
                root.right = self.bstFromPreorder(preorder[i: ])
                return root
        else:
            root.left = self.bstFromPreorder(preorder[1:])
            return root

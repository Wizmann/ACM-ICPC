# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

INF = 0xdeadbeef

class Solution:
    # @param root, a tree node
    # @return an integer
    def maxPathSum(self, root):
        if not root:
            return 0
        self.maxi = -INF
        self._maxPathSum(root)
        return self.maxi
        
    def _maxPathSum(self, root):
        if not root:
            return 0
        l = self._maxPathSum(root.left)
        r = self._maxPathSum(root.right)
        self.maxi = max(self.maxi, root.val + l + r, root.val + l, root.val + r, root.val)
        return root.val + max(0, l, r)

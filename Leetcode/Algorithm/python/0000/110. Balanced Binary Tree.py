# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a boolean
    def isBalanced(self, root):
        (depth, balanced) = self._isBalanced(root)
        return balanced
        
    def _isBalanced(self, root):
        if not root:
            return (0, True)
        (left_depth, left_balanced)   = self._isBalanced(root.left)
        (right_depth, right_balanced) = self._isBalanced(root.right)
        depth = max(left_depth, right_depth) + 1
        balanced = abs(left_depth - right_depth) <= 1 and left_balanced and right_balanced
        return (depth, balanced)

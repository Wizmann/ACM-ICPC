# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def levelOrderBottom(self, root):
        if not root:
            return []
        res = []
        now_level = [root]
        next_level = []
        while now_level:
            for node in now_level:
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            res.append(map(lambda x: x.val, now_level))
            now_level = next_level
            next_level = []
        return res[::-1]

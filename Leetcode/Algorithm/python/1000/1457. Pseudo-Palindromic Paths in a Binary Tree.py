# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def pseudoPalindromicPaths (self, root):
        self.res = 0
        self.dfs(root, 0)
        return self.res
    
    def dfs(self, root, bits):
        if not root:
            return
        bits ^= 1 << root.val
        if not root.left and not root.right:
            # print bits
            if bits == 0 or (bits & (bits - 1)) == 0:
                self.res += 1
            return
        
        self.dfs(root.left, bits)
        self.dfs(root.right, bits)

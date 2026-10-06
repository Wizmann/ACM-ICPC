# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def averageOfSubtree(self, root):
        self.res = 0
        self.dfs(root)
        return self.res
    
    def dfs(self, root):
        if root == None:
            return (0, 0) # cnt, sum
        
        left_cnt, left_sum = self.dfs(root.left)
        right_cnt, right_sum = self.dfs(root.right)
        
        if (left_sum + right_sum + root.val) / (left_cnt + right_cnt + 1) == root.val:
            self.res += 1
            
        return ( (left_cnt + right_cnt + 1), (left_sum + right_sum + root.val) )
        

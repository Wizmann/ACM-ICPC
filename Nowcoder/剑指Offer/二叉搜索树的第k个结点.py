# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回对应节点TreeNode
    def KthNode(self, pRoot, k):
        self.cnt = k
        return self.dfs(pRoot)
        
    def dfs(self, root):
        if root == None:
            return None
        res = self.dfs(root.left)
        if res:
            return res
        self.cnt -= 1
        if self.cnt == 0:
            return root
        
        res = self.dfs(root.right)
        if res:
            return res
        return None
        

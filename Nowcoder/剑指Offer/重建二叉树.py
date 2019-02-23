# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        if not pre:
            return None
        rv = pre.pop(0)
        ri = tin.index(rv)
        root = TreeNode(rv)
        root.left = self.reConstructBinaryTree(pre[:ri], tin[:ri])
        root.right = self.reConstructBinaryTree(pre[ri:], tin[ri + 1:])
        return root

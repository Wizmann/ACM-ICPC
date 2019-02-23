# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def HasSubtree(self, pRoot1, pRoot2, isRoot=True):
        if isRoot and not pRoot2:
            return False
        if not pRoot1 and not pRoot2:
            return True
        if not pRoot1:
            return False
        if not pRoot2:
            return True
        
        flag = False
        if not flag and pRoot1.val == pRoot2.val:
            flag |= self.HasSubtree(pRoot1.left, pRoot2.left, False) and \
                    self.HasSubtree(pRoot1.right, pRoot2.right, False)
        if not flag:
            flag |= self.HasSubtree(pRoot1.left, pRoot2, False)
        if not flag:
            flag |= self.HasSubtree(pRoot1.right, pRoot2, False)
        return flag

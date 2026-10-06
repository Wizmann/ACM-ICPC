# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

INF = 10 ** 10

class Solution(object):
    def str2tree(self, s):
        self.ptr = 0
        self.s = s
        
        return self.make_tree()
        
    def make_tree(self):
        s = self.s[self.ptr:]
        if not s:
            return None
        
        
        idx1 = INF if '(' not in s else s.index('(')
        idx2 = INF if ')' not in s else s.index(')')

        if idx1 < idx2:
            v = int(s[:idx1])
        elif idx2 == 0:
            return None
        else:
            v = int(s[:idx2])
            self.ptr += idx2 + 1
            return TreeNode(v)
        
        self.ptr += idx1 + 1
        node_l = self.make_tree()
        
        if self.ptr < len(self.s) and self.s[self.ptr] != ')':
            self.ptr += 1
        node_r = self.make_tree()
        self.ptr += 1

        root = TreeNode(v)
        root.left = node_l
        root.right = node_r
        return root

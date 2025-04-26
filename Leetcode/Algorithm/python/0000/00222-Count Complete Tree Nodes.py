# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def countNodes(self, root):
        if not root:
            return 0
        
        (ll, lr) = self.get_depth(root.left)
        (rl, rr) = self.get_depth(root.right)
        if ll == rr:
            return (2 ** (ll + 1)) - 1
        
        if ll == lr:
            a = (2 ** ll) - 1
            b = self.countNodes(root.right)
            return a + b + 1
        else:
            a = self.countNodes(root.left)
            b = (2 ** rr) - 1
            return a + b + 1
            
    def get_depth(self, root):
        l, r = 0, 0
        
        a = root
        while a:
            l += 1
            a = a.left
        
        b = root
        while b:
            r += 1
            b = b.right
        
        return (l, r)

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def constructFromPrePost(self, pre, post):
        if not pre:
            return None
        cur = TreeNode(pre[0])
        self.build(cur, pre[1:], post[:-1])
        return cur
    
    def build(self, cur, pre, post):
        if not pre:
            return None
        a, b = pre[0], post[-1]
        
        l = TreeNode(a)
        cur.left = l
        
        if a != b:
            r = TreeNode(b)
            cur.right = r
        
            self.build(l, pre[1:pre.index(b)], post[:post.index(a)])
            self.build(r, pre[pre.index(b) + 1:], post[post.index(a) + 1: -1])        
        else:
            self.build(l, pre[1:], post[:-1])

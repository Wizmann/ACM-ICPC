# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderSuccessor(self, root, p):
        if p.right:
            p = p.right
            while p.left:
                p = p.left
            return p
        else:
            st = []
            while root != p:
                st.append(root)
                if p.val < root.val:
                    root = root.left
                else:
                    root = root.right
                    
            pre = p
            cur = None
            while st:
                cur = st.pop()
                if cur.left == pre:
                    return cur
                else:
                    pre = cur
            return None
                    

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def boundaryOfBinaryTree(self, root):
        if not root:
            return []
        l = self.get_boundary(root, lambda x: x.left, lambda x: x.right)
        r = self.get_boundary(root, lambda x: x.right, lambda x: x.left)[::-1]
        leaves = self.get_leaves(root)
        
        if id(l[-1]) == id(leaves[0]):
            l.pop()
        l += leaves
        if id(l[-1]) == id(r[0]):
            l.pop()
        l += r
        if len(l) > 1 and id(l[0]) == id(l[-1]):
            l.pop()
        return map(lambda node: node.val, l)

    def get_boundary(self, root, m1, m2):
        res = []
        if not m1(root):
            return [root]
        while root:
            res.append(root)
            if not root.left and not root.right:
                break
            l = m1(root)
            if l:
                root = l
            else:
                root = m2(root)
        return res
    
    def get_leaves(self, root):
        st = []
        res = []
        while True:
            if root:
                st.append(root)
                root = root.left
            elif st:
                root = st.pop()
                if not root.left and not root.right:
                    res.append(root)
                root = root.right
            else:
                break
        return res

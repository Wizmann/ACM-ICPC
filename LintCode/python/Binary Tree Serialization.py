"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        this.val = val
        this.left, this.right = None, None
"""

class Traversal(object):
    def __init__(self):
        self._pre_order = []
        self._in_order  = []
    
    def pre_order(self, root):
        self._pre_order = []
        self.do_pre_order(root)
        return self._pre_order
    
    def in_order(self, root):
        self._in_order = []
        self.do_in_order(root)
        return self._in_order
    
    def do_pre_order(self, root):
        self._pre_order.append(root)
        if root.left:
            self.do_pre_order(root.left)
        if root.right:
            self.do_pre_order(root.right)
    
    def do_in_order(self, root):
        if root.left:
            self.do_in_order(root.left)
        self._in_order.append(root)
        if root.right:
            self.do_in_order(root.right)

class Solution:
    '''
    @param root: An object of TreeNode, denote the root of the binary tree.
    This method will be invoked first, you should design your own algorithm 
    to serialize a binary tree which denote by a root node to a string which
    can be easily deserialized by your own "deserialize" method later.
    '''
    def serialize(self, root):
        if not root:
            return None
        t = Traversal()
        preorder = t.pre_order(root)
        inorder  = t.in_order(root)
        return (preorder, inorder)

    '''
    @param data: A string serialized by your serialize method.
    This method will be invoked second, the argument data is what exactly
    you serialized at method "serialize", that means the data is not given by
    system, it's given by your own serialize method. So the format of data is
    designed by yourself, and deserialize it here as you serialize it in 
    "serialize" method.
    '''
    def deserialize(self, data):
        if not data or len(data) != 2:
            return None
            
        preorder = data[0]
        inorder  = data[1]
        
        if not preorder or not inorder:
            return None
        
        n = len(inorder)
        d = dict(
                zip(
                    map(lambda x: x.val, inorder), 
                    range(n)
                )
            )
        
        return self.do_deserialize(preorder, inorder, d)
        
    def do_deserialize(self, preorder, inorder, d):
        if not preorder:
            return None
        
        root = preorder[0]
        left = inorder[0]
        idx = d[root.val] - d[left.val]
        
        root.left  = self.do_deserialize(
                        preorder[1: 1 + idx],
                        inorder[:idx],
                        d)
        root.right = self.do_deserialize(
                        preorder[1 + idx:],
                        inorder[1 + idx:],
                        d)
        return root

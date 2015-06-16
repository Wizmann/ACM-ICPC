"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        this.val = val
        this.left, this.right = None, None
"""
class Solution:
    # @param root: a TreeNode, the root of the binary tree
    # @return: nothing
    def invertBinaryTree(self, root):
        st = [root]
        while st:
            node = st.pop()
            node.left, node.right = node.right, node.left
            if node.left:
                st.append(node.left)
            if node.right:
                st.append(node.right)
        return root

# https://leetcode.com/problems/balance-a-binary-search-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        nodes = []
        for item in self.traverse(root):
            nodes.append(TreeNode(item.val))
        return self.buildTree(nodes)
        
    def traverse(self, root):
        if not root:
            return
        yield from self.traverse(root.left)
        yield root
        yield from self.traverse(root.right)
        
    def buildTree(self, nodes):
        if not nodes:
            return None
        n = len(nodes)
        cur = nodes[n // 2]
        cur.left = self.buildTree(nodes[: n // 2])
        cur.right = self.buildTree(nodes[n // 2 + 1:])
        return cur
        

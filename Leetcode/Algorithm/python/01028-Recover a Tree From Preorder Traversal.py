# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import re

class Solution(object):
    def recoverFromPreorder(self, S):
        self.nodes = self.makeNodes(S)
        return self.dfs(0)
    
    def makeNodes(self, S):
        nodes = []
        S = filter(lambda x: x, re.split("(-)", S))
        while S:
            depth = 0
            while S and S[0] == '-':
                depth += 1
                S.pop(0)
            value = int(S[0])
            S.pop(0)
            nodes.append((value, depth))
        return nodes
    
    def dfs(self, depth):
        if not self.nodes:
            return None
        if depth != self.nodes[0][1]:
            return None
            
        value, _ = self.nodes[0]
        self.nodes.pop(0)
        node = TreeNode(value)
        node.left = self.dfs(depth + 1)
        node.right = self.dfs(depth + 1)
        return node
        
        

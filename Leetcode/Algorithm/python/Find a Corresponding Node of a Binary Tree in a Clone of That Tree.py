# https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        path = self.dfs1(original, target, [])
        return self.dfs2(cloned, path)
    
    def dfs1(self, cur, target, path):
        if not cur:
            return []
        if cur.val == target.val:
            return path
        p1 = self.dfs1(cur.left, target, path + ["L"])
        if p1:
            return p1
        p2 = self.dfs1(cur.right, target, path + ["R"])
        if p2:
            return p2
        return []
    
    def dfs2(self, cur, path):
        if not path:
            return cur
        if path[0] == 'L':
            return self.dfs2(cur.left, path[1:])
        else:
            return self.dfs2(cur.right, path[1:])
            
            

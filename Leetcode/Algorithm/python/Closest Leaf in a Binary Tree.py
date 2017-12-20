# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

INF = 10 ** 10

class Solution(object):
    def findClosestLeaf(self, root, k):
        if not root:
            return None
        
        self.dfs1(root)
        (dis, node) = self.dfs2(root, k, INF, None)
        return node
    
    def dfs1(self, root):
        root.dis = [INF, None]
        
        if root.left:
            res = self.dfs1(root.left)[:]
            res[0] += 1
            root.dis = min(root.dis, res)
            
        if root.right:
            res = self.dfs1(root.right)[:]
            res[0] += 1
            root.dis = min(root.dis, res)
            
        if not root.left and not root.right:
            root.dis = [0, root]
            
        return root.dis
        
    
    def dfs2(self, root, k, mini, prenode):
        if not root:
            return (INF, None)
        
        if root.dis[0] < mini:
            mini = root.dis[0]
            prenode = root

        
        if root.val == k:
            if mini < root.dis[0]:
                return (mini, prenode.dis[1].val)
            else:
                return (root.dis[0], root.dis[1].val)
        
        return min(self.dfs2(root.left, k, mini + 1, prenode), self.dfs2(root.right, k, mini + 1, prenode))
        
        

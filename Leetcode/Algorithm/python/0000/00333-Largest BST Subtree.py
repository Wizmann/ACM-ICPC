# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

INF = 10 ** 10

class Solution(object):
    def largestBSTSubtree(self, root):
        self.res = 0
        self.dfs(root)
        return self.res
    
    def dfs(self, root):
        if not root:
            return (-INF, INF, -INF)
        if not root.left and not root.right:
            self.res = max(self.res, 1)
            return (root.val, root.val, 1)
        
        (mini1, maxi1, size1) = self.dfs(root.left)
        (mini2, maxi2, size2) = self.dfs(root.right)
        
        mini, maxi, size = root.val, root.val, -1
        
        if size1 > 0:
            if mini1 <= maxi1 < root.val:
                if size == -1:
                    size = 1 + size1
                else:
                    size += size1
                mini = mini1
            else:
                return (-1, -1, -1)
        elif size1 == -INF:
            pass
        else:
            return (-1, -1, -1)
        
        if size2 > 0:
            if root.val < mini2 <= maxi2:
                if size == -1:
                    size = 1 + size2
                else:
                    size += size2
                maxi = maxi2
            else:
                return (-1, -1, -1)
        elif size2 == -INF:
            pass
        else:
            return (-1, -1, -1)
        
        self.res = max(self.res, size)
        print (mini, maxi, size)
        return (mini, maxi, size)
        

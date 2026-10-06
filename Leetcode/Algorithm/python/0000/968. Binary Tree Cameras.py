# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

INF = 10 ** 10

class Solution(object):
    def minCameraCover(self, root):
        self.d = {}
        return max(1, self.dfs(root, False, False))
        
    def dfs(self, root, pre, must):
        if not root:
            return 0
        
        key = id(root) * 4 + pre * 2 + must
        if key in self.d:
            return self.d[key]
        
        res = INF
        res = min(res, self.dfs(root.left, True, False) + self.dfs(root.right, True, False) + 1)

        if not must: 
            if pre:
                res = min(res, self.dfs(root.left, False, False) + self.dfs(root.right, False, False))
            else:
                if not root.left and not root.right:
                    res = 1
                if root.left:
                    res = min(res, self.dfs(root.left, False, True) + self.dfs(root.right, False, False))
                if root.right:
                    res = min(res, self.dfs(root.left, False, False) + self.dfs(root.right, False, True))


        self.d[key] = res
        return res

##################################

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

NOT_MONITORED = 0
MONITORED = 1
CAMERA = 2

class Solution(object):
    def minCameraCover(self, root):
        self.res = 0
        if not root:
            return 0
        return (1 if self.solve(root) == NOT_MONITORED else 0) + self.res

    def solve(self, root):
        if not root:
            return MONITORED
        
        if not root.left and not root.right:
            return NOT_MONITORED
        
        l = MONITORED
        if root.left:
            l = self.solve(root.left)
            
        r = MONITORED
        if root.right:
            r = self.solve(root.right)
        if l == NOT_MONITORED or r == NOT_MONITORED:
            self.res += 1
            return CAMERA
        elif l == MONITORED and r == MONITORED:
            return NOT_MONITORED
        else:
            return MONITORED

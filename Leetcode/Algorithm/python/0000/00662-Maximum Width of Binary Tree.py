# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.d = {}
        
    def widthOfBinaryTree(self, root):
        self.dfs(root, 1, 1)
        ans = 0
        for key, value in self.d.items():
            ans = max(ans, max(value) - min(value))
        return ans + 1
    
    def dfs(self, cur, nr, depth):
        if depth not in self.d:
            self.d[depth] = [nr]
        else:
            self.d[depth].append(nr)
            
        if cur.left != None:
            self.dfs(cur.left, nr * 2 - 1, depth + 1)
        if cur.right != None:
            self.dfs(cur.right, nr * 2, depth + 1)
        
        

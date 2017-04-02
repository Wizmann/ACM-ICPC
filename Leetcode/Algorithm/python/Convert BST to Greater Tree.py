class Solution(object):
    def convertBST(self, root):
        self.sum = 0
        self.dfs(root)
        return root
        
    def dfs(self, root):
        if not root:
            return None
            
        self.dfs(root.right)
        self.sum, root.val = self.sum + root.val, root.val + self.sum
        self.dfs(root.left)

class Solution(object):
    def dfs(self, root):
        if not root:
            return 0
        lw = self.dfs(root.left)
        rw = self.dfs(root.right)
        
        self.ans += abs(lw - rw)
        return lw + rw + root.val
        
    def findTilt(self, root):
        self.ans = 0
        self.dfs(root)
        return self.ans

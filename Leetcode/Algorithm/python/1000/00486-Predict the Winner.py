class Solution(object):
    def PredictTheWinner(self, nums):
        self.d = {}
        n = len(nums)
        return self.dfs(nums, 0, n - 1) >= 0
        
    def dfs(self, nums, l, r):
        if (l, r) in self.d:
            return self.d[(l, r)]
            
        if l == r:
            return nums[l]
            
        a = nums[l] - self.dfs(nums, l + 1, r)
        b = nums[r] - self.dfs(nums, l, r - 1)
        
        self.d[(l, r)] = max(a, b)
        
        return self.d[(l, r)]

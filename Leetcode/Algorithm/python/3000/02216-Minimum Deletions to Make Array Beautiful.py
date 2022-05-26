class Solution(object):
    def minDeletion(self, nums):
        n = len(nums)
        self.d = {}
        return n - self.dfs(0, nums)
    
    def dfs(self, cur, nums):
        n = len(nums)
        if cur == n or cur + 1 == n:
            return 0
        if cur in self.d:
            return self.d[cur]
        maxi = 0
        if nums[cur] == nums[cur + 1]:
            maxi = max(maxi, self.dfs(cur + 1, nums))
        else:
            maxi = max(maxi, self.dfs(cur + 2, nums) + 2)
        self.d[cur] = maxi
        return maxi
            

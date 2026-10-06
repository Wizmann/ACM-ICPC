INF = 10 ** 10

class Solution(object):
    def movesToMakeZigzag(self, nums):
        return min(self.solve(nums, 0), self.solve(nums, 1))
    
    def solve(self, nums, zigzag):
        n = len(nums)
        ans = 0
        for i in xrange(zigzag, n, 2):
            num = nums[i]
            left = INF if i - 1 < 0 else nums[i - 1]
            right = INF if i + 1 >= n else nums[i + 1]
            
            ans += max(0, num - min(left, right) + 1)
        return ans

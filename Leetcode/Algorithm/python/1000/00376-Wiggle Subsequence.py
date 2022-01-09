INF = 10 ** 10

class Solution(object):
    def wiggleMaxLength(self, nums):
        return max(self.solve(nums, 1), self.solve(nums, -1))
    
    def solve(self, nums, p):
        pre = -p * INF
        cnt = 0
        for num in nums:
            if (p > 0 and num > pre) or (p < 0 and num < pre):
                p = -p
                cnt += 1
            pre = num
        return cnt

            

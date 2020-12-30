class Solution(object):
    def maxSubArrayLen(self, nums, k):
        d = {0: -1}
        pre = 0
        ans = 0
        for i, num in enumerate(nums):
            pre += num
            if pre - k in d:
                ans = max(ans, i - d[pre - k])
            if pre not in d:
                d[pre] = i
        return ans
        

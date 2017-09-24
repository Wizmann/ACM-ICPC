INF = 0x3f3f3f3f

class Solution(object):
    def findLengthOfLCIS(self, nums):
        pre = -INF
        cnt = 0
        ans = 0
        for num in nums:
            if num > pre:
                cnt += 1
            else:
                ans = max(ans, cnt)
                cnt = 1
            pre = num
        return max(ans, cnt)

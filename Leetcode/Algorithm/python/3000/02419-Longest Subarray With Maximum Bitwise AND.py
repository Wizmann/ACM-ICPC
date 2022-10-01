INF = 10 ** 100

class Solution(object):
    def longestSubarray(self, nums):
        pre = -INF
        cnt = 0
        maxv = 0
        maxi = 0
        for num in nums:
            if num == pre:
                cnt += 1
            else:
                cnt = 1
                pre = num
            if pre > maxv:
                maxv = pre
                maxi = cnt
            elif pre == maxv:
                maxi = max(maxi, cnt)
        return maxi

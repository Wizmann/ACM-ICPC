INF = 10 ** 10

class Solution(object):
    def minimumAverageDifference(self, nums):
        n = len(nums)
        left = 0
        right = sum(nums)
        mini = INF
        minv = 0
        for i in xrange(n):
            left += nums[i]
            right -= nums[i]
            ave_left = left / (i + 1)
            ave_right = 0 if i == n - 1 else right / (n - i - 1)
            ans = abs(ave_left - ave_right)
            if ans < mini:
                mini = ans
                minv = i
            # print i, ans, mini
        return minv

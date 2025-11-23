class Solution(object):
    def maxBalancedSubarray(self, nums):
        d = {(0, 0): -1}

        ans = 0
        pre1, pre2 = 0, 0
        for i, num in enumerate(nums):
            pre1 += 1 if num % 2 else -1
            pre2 ^= num

            if (pre1, pre2) in d:
                ans = max(ans, i - d[(pre1, pre2)])
            else:
                d[(pre1, pre2)] = i
        return ans

class Solution(object):
    def maxDivScore(self, nums, divisors):
        maxv = -1
        maxi = -1

        for div in sorted(set(divisors)):
            cnt = 0
            for num in nums:
                cnt += 1 if num % div == 0 else 0
            if cnt > maxv:
                maxv = cnt
                maxi = div
        return maxi

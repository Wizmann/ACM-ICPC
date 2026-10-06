def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

class Solution(object):
    def countBeautifulPairs(self, nums):
        n = len(nums)
        cnt = 0
        for i in xrange(n):
            for j in xrange(i + 1, n):
                a = int(str(nums[i])[0])
                b = int(str(nums[j])[-1])
                if gcd(a, b) == 1:
                    cnt += 1
        return cnt

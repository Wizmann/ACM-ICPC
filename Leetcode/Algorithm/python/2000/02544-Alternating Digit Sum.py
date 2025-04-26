class Solution(object):
    def alternateDigitSum(self, n):
        ns = map(int, str(n))
        ans = 0
        for i, num in enumerate(ns):
            ans += num * ((-1) ** i)
        return ans

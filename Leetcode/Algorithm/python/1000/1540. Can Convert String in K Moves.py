from collections import defaultdict

class Solution(object):
    def canConvertString(self, s, t, k):
        d = defaultdict(int)
        if len(s) != len(t):
            return False
        n = len(s)
        for i in xrange(n):
            diff = ((ord(t[i]) - ord(s[i])) % 26 + 26) % 26
            d[diff] += 1
        maxi = 0
        for key, value in d.items():
            if key == 0 or value == 0:
                continue
            maxi = max(maxi, key + 26 * (value - 1))
        return not (maxi > k)

assert Solution().canConvertString("input", "ouput", 9) == True

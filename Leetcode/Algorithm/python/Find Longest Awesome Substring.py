class Solution(object):
    def longestAwesome(self, s):
        d = {0: -1}
        cur = 0
        res = 0
        for i, c in enumerate(s):
            u = int(c)
            cur ^= 1 << u
            mask = cur
            if mask in d:
                res = max(res, i - d[mask])
            for j in xrange(10):
                mask1 = mask ^ (1 << j)
                if mask1 in d:
                    res = max(res, i - d[mask1])
            if cur not in d:
                d[cur] = i
        return res

assert Solution().longestAwesome("1") == 1
assert Solution().longestAwesome("11") == 2
assert Solution().longestAwesome("123") == 1
assert Solution().longestAwesome("1213") == 3

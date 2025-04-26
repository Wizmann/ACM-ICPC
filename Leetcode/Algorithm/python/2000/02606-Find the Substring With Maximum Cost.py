class Solution(object):
    def maximumCostSubstring(self, s, chars, vals):
        d = {}
        for i in xrange(1, 27):
            d[chr(ord('a') + i - 1)] = i
        for (c, v) in zip(chars, vals):
            d[c] = v
        s = map(lambda x: d[x], s)
        maxi = 0
        cur = 0
        for num in s:
            cur += num
            maxi = max(maxi, cur)
            if cur < 0:
                cur = 0
        return maxi

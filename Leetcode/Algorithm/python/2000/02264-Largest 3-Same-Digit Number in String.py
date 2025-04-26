class Solution(object):
    def largestGoodInteger(self, num):
        n = len(num)
        res = ''
        for i in xrange(n - 2):
            cur = num[i: i + 3]
            if len(set(cur)) > 1:
                continue
            res = max(res, cur)
        return res

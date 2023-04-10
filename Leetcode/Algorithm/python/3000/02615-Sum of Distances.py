class Solution(object):
    def distance(self, nums):
        n = len(nums)
        self.res = [0 for i in xrange(n)]

        d = {}
        for i in xrange(n):
            cur = nums[i]
            if cur not in d:
                d[cur] = (i, 1, 0)
            else:
                (pre, cnt, dis) = d[cur]
                dd = cnt * (i - pre) + dis
                self.res[i] += dd
                d[cur] = (i, cnt + 1, dd)
                
        d = {}
        for i in xrange(n - 1, -1, -1):
            cur = nums[i]
            if cur not in d:
                d[cur] = (i, 1, 0)
            else:
                (pre, cnt, dis) = d[cur]
                dd = cnt * (pre - i) + dis
                self.res[i] += dd
                d[cur] = (i, cnt + 1, dd)
        return self.res


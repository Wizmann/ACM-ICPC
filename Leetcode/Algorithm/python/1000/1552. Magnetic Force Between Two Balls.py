INF = 10 ** 10
class Solution(object):
    def maxDistance(self, position, n):
        position.sort()
        l, r = 1, position[-1] - position[0]
        while l <= r:
            m = (l + r) / 2
            if self.check(position, n, m):
                l = m + 1
            else:
                r = m - 1
        return r

    def check(self, ps, n, m):
        pre = 0
        for i in xrange(n - 1):
            cur = pre + 1
            while cur < len(ps):
                if ps[cur] >= ps[pre] + m:
                    pre = cur
                    break
                cur += 1
            if cur == len(ps):
                return False
        return True


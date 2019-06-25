INF = 10 ** 10

class Solution(object):
    def findInMountainArray(self, secret, target):
        n = len(secret)
        l, r = 0, n - 1
        maxip = -1
        maxiv = -INF
        while l <= r:
            m = (r - l + 1)
            p1 = l + m / 3
            p2 = r - m / 3
            v1 = secret[p1]
            v2 = secret[p2]
            
            if v1 > maxiv:
                maxiv = v1
                maxip = p1
            
            if v2 > maxiv:
                maxiv = v2
                maxip = p2
            
            if v1 < v2:
                l = p1 + 1
            else:
                r = p2 - 1
        self.res = []
        self.find(secret, 0, maxip, target, lambda x, y: x < y)
        self.find(secret, maxip, n - 1, target, lambda x, y: x > y)
        if self.res:
            return min(self.res)
        else:
            return -1
        
    def find(self, secret, l, r, t, c):
        while l <= r:
            m = (l + r) >> 1
            if c(secret[m], t):
                l = m + 1
            else:
                r = m - 1
        if 0 <= l < len(secret) and secret[l] == t:
            self.res.append(l)

assert Solution().findInMountainArray([1, 5, 2], 0) == -1
assert Solution().findInMountainArray([0, 1, 2, 4, 3, 2], 3) == 4
assert Solution().findInMountainArray([1, 2, 3, 4, 5, 3, 1], 3) == 2

INF = 10 ** 100

class Solution(object):
    def kthDigit(self, k):
        l, r = 0, 10 ** 15
        while l <= r:
            m = (l + r) / 2
            cnt = self.count(m)
            if cnt > k:
                r = m - 1
            else:
                l = m + 1
        delta = k - self.count(r)
        ns = [l * 10 + i for i in xrange(10)]
        if r % 2 == 0:
            ns = ns[::-1]
        s = ''.join(map(str, ns))
        print s
        return int(s[delta])
        
    def count(self, x):
        """Return the number of decimal digits in blocks 0 through x."""
        if x < 0:
            return 0

        # Block 0 contains 1 through 9.  For b >= 1, all ten numbers in
        # block b have one more digit than b itself.
        cnt = 10
        for i in xrange(0, 123456):
            base = 10 ** i
            if base > x:
                break
            if x >= base * 10:
                rem = base * 9
            else:
                rem = x - base + 1
            cnt += rem * (i + 2) * 10
        return cnt


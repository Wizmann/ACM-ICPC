INF = 10 ** 10

class Solution(object):
    def minOperations(self, s):
        n = len(s)
        s = list(s)
        mini = INF
        for i in xrange(n):
            if i >= mini:
                break
            mini = min(mini, self.solve(s) + i)
            s = s[1:] + [s[0]]
        return mini

    def solve(self, s):
        n = len(s)
        l, r = 0, n - 1
        tot = 0
        while l < r:
            a, b = ord(s[l]) - ord('a'), ord(s[r]) - ord('a')
            tot += min(abs(a - b), 26 - a + b, 26 - b + a)
            l += 1
            r -= 1
        return tot

INF = 10 ** 10
class Solution(object):
    def isTransformable(self, s, t):
        if sorted(s) != sorted(t):
            return False

        ps = [ [] for i in xrange(10) ]
        for i, c in enumerate(t):
            c = int(c)
            ps[int(c)].append(i)
        s = map(int, list(s))
        n = len(s)

        qs = [ -INF for i in xrange(n) ]
        for i in xrange(10):
            p = 0
            for j in xrange(n):
                if s[j] == i:
                    if qs[j] > ps[i][p]:
                        return False
                    qs[j] = ps[i][p]
                    p += 1
                if j - 1 >= 0:
                    qs[j] = max(qs[j], qs[j - 1])
        return True

assert Solution().isTransformable("432513576", "231435567")
assert Solution().isTransformable("12345", "12435") == False
assert Solution().isTransformable("34521", "23415")
assert Solution().isTransformable("84532", "34852")

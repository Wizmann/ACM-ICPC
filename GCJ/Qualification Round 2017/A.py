def bit_count(x):
    res = 0
    while x:
        res += (x & 1)
        x >>= 1
    return res

class Solution(object):
    def __init__(self, s, m):
        self.s = s
        self.n = len(s)
        self.m = m

    def brute_force(self):
        s = self.s[:]
        ans = 10 ** 10
        for i in xrange(1 << (self.n - self.m + 1)):
            ss = list(s[:])
            for j in xrange(self.n):
                if i & (1 << j):
                    for k in xrange(self.m):
                        ss[j + k] = '+' if ss[j + k] == '-' else '-'
            if set(ss) == set(['+']):
                ans = min(ans, bit_count(i))
        return ans

    def solve(self):
        s = list(self.s[:])
        ans = 0
        for i in xrange(self.n - self.m + 1):
            if s[i] == '-':
                for j in xrange(self.m):
                    s[i + j] = '+' if s[i + j] == '-' else '-'
                ans += 1
        if set(s) == set(['+']):
            return ans
        else:
            return 10 ** 10


assert Solution('---+-++-', 3).brute_force() == 3
assert Solution('---+-++-', 3).solve() == 3
assert Solution('+++++', 4).solve() == 0
assert Solution('-+-+-', 4).solve() == 10 ** 10

N = 7
for i in xrange(1 << N):
    s = ''
    for j in xrange(N):
        if i & (1 << j):
            s += '+'
        else:
            s += '-'

    for j in xrange(1, N + 1):
        S = Solution(s, j)
        assert S.solve() == S.brute_force()



if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        (s, t) = raw_input().split()
        print 'Case #%d:' % (case_ + 1),

        S = Solution(s, int(t))
        ans = S.solve()
        if ans == 10 ** 10:
            ans = 'IMPOSSIBLE'
        print ans

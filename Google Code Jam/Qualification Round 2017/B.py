def is_non_decending(num):
    s = map(int, str(num))
    n = len(s)

    for i in xrange(n - 1):
        if s[i] > s[i + 1]:
            return False
    return True

assert is_non_decending(1)
assert is_non_decending(123)
assert not is_non_decending(321)
assert not is_non_decending(32)


class Solution(object):
    def __init__(self, n):
        self.n = n

    def brute_force(self):
        n = self.n
        while n:
            if is_non_decending(n):
                return n
            n -= 1

    def solve(self):
        s = map(int, str(self.n))
        self.tmp = []
        self.dfs(s, 0, len(s))
        return int(''.join(map(str, self.tmp)))

    def dfs(self, s, cur, n):
        if cur == n:
            return True
        for i in xrange(9, -1, -1):
            a = int(''.join(map(str, s[:cur + 1])))
            b = int(''.join(map(str, self.tmp + [i])))
            if (not self.tmp or self.tmp[-1] <= i) and a >= b:
                self.tmp.append(i)
                if self.dfs(s, cur + 1, n):
                    return True
                self.tmp.pop()
        return False

assert Solution(132).solve() == 129
assert Solution(1000).solve() == 999
assert Solution(7).solve() == 7
assert Solution(111111111111111110).solve() == 99999999999999999

for i in xrange(1, 10000):
    S = Solution(i)
    assert S.solve() == S.brute_force()

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        n = int(raw_input())
        S = Solution(n)
        print 'Case #%d: %d' % (case_ + 1, S.solve())

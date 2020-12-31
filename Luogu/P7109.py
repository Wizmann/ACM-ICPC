import sys
import random

INF = 10 ** 10

class ITester(object):
    def __init__(self):
        pass

    def query(self, a, b):
        raise NotImplementedError

class OfflineTester(object):
    def __init__(self, ns):
        self.n = len(ns) - 1
        self.ns = ns
        self.ans = ns[:]
        self.cnt = 0

    def query(self, a, b):
        self.cnt += 1
        assert self.cnt < 20000
        assert min(a, b) >= 1 and max(a, b) <= self.n
        if a == b:
            return 1 if self.ns[a] == a else 0
        else:
            tot = self.ns[a] + self.ns[b]
            trans = min(self.ns[a], b - self.ns[b])
            self.ns[a] -= trans
            self.ns[b] += trans
            assert tot == self.ns[a] + self.ns[b]
            assert 0 <= self.ns[a] <= a
            assert 0 <= self.ns[b] <= b
            return 1 if self.ns[b] == b else 0

    def check(self, ms):
        return ms[1:] == self.ans[1:]

class OnlineTester(object):
    def __init__(self):
        pass

    def query(self, a, b):
        print '?', a, b
        sys.stdout.flush()
        return int(raw_input())

    def check(self, ms):
        print '!', ' '.join(map(str, ms[1:]))
        sys.stdout.flush()
        return True

class Solution(object):
    def __init__(self, n, tester):
        self.n = n
        self.tester = tester

    def solve(self):
        self.ns = [-1 for i in xrange(self.n + 1)]
        self.ans = [-1 for i in xrange(self.n + 1)]
        tot = 0
        for i in xrange(1, self.n + 1):
            cur = self.do_solve(i, 0)
            self.ans[i] = cur - tot
            tot = cur
        return self.ans

    def check(self):
        return self.tester.check(self.ans)

    def do_solve(self, cur, depth):
        if cur == 1:
            res = self.tester.query(1, 1)
            self.ns[1] = res
            return res

        last = cur
        for i in xrange(1, cur):
            if self.ns[i] == i:
                continue
            res = self.tester.query(cur, i)
            if res == 1:
                self.ns[i] = i
            else:
                last = i
                break

        if last == 1:
            res = self.tester.query(1, 1)
            self.ns[1] = res
            return res

        if last == cur and self.tester.query(cur, cur) == 1:
            self.ns[cur] = cur
            return (1 + cur) * cur / 2

        l, r = 1, last - 1
        while l <= r:
            m = (l + r) / 2
            res = self.tester.query(m, last)
            if res == 1:
                r = m - 1
            else:
                l = m + 1
            self.tester.query(last, m)

        return (last - l) + (last * (last - 1)) / 2

def test(ns):
    n = len(ns) - 1
    tester = OfflineTester(ns)
    s = Solution(n, tester)
    s.solve()
    assert s.check()

test([0, 0, 2, 3])
test([0, 1, 0, 3])
test([0, 1, 1, 2])
test([0, 1, 2, 3])
test([0, 1, 0, 1])
test([0, 0, 0, 1, 2])

tester5 = OfflineTester([0, 0, 0, 1])
s5 = Solution(3, tester5)
s5.solve()
assert s5.check()

tester4 = OfflineTester([0, 0, 0, 0])
s4 = Solution(3, tester4)
s4.solve()
assert s4.check()

tester3 = OfflineTester([0, 1, 0])
s3 = Solution(2, tester3)
s3.solve()
assert s3.check()

'''
for i in xrange(100):
    n = 1000
    ns = [random.randint(0, i) for i in xrange(0, n + 1)]
    test(ns)
'''

t = OnlineTester()
n = int(raw_input())
s = Solution(n, t)
s.solve()
s.check()


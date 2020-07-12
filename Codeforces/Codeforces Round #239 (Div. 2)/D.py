MOD = (10 ** 9) + 7

class Solution(object):
    def __init__(self, ns):
        self.n = len(ns)
        self.ns = [-1] + ns

    def solve(self):
        self.d = {}
        res = 0
        for i in xrange(self.n + 1, 1, -1):
            res += self.do_solve(i - 1) + 1
            res %= MOD
        # print self.d
        # print res
        return res

    def brute_force(self):
        mark = [0 for i in xrange(self.n + 2)]
        cur = 1
        step = 0
        while cur != self.n + 1:
            mark[cur] ^= 1
            if mark[cur] == 1:
                cur = self.ns[cur]
            else:
                cur += 1
            step += 1
            # print mark
        return step

    def do_solve(self, p):
        if p == 1:
            return 1
        if p in self.d:
            return self.d[p]
        res = 1
        pre = self.ns[p]
        for i in xrange(pre, p):
            res += self.do_solve(i) + 1
            res %= MOD
        self.d[p] = res
        return res

assert Solution([1, 1, 1]).solve() == 14
assert Solution([1, 2]).solve() == 4
assert Solution([1, 1, 2]).solve() == 12
assert Solution([1]).solve() == 2
assert Solution([1, 1]).solve() == 6
assert Solution([1, 1, 3]).solve() == 8
assert Solution([1, 1, 1, 1, 1]).brute_force() == 62
assert Solution([1, 2, 3]).solve() == 6
assert Solution([1, 1, 2, 3]).solve() == 20
assert Solution([1, 1, 1, 1, 1]).solve() == 62

if __name__ == '__main__':
    n = int(raw_input())
    ns = map(int, raw_input().split())
    print Solution(ns).solve()

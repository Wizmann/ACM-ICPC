class Solution(object):
    def __init__(self, ns):
        self.ns = ns
        self.nsbk = ns[:]

    def solve(self):
        tot = sum(self.ns)
        ans = []
        while tot:
            maxi = 0
            ps = []

            for i, value in enumerate(self.ns):
                if not value:
                    continue
                if value > maxi:
                    ps = [i]
                    maxi = value
                elif value == maxi:
                    ps.append(i)

            if len(ps) == 1:
                self.ns[ps[0]] -= 1
                tot -= 1
                ans.append((ps[0], -1))
            elif tot == 3 and len(ps) == 3:
                self.ns[ps[0]] -= 1
                tot -= 1
                ans.append((ps[0], -1))
            else:
                a, b = ps[:2]
                self.ns[a] -= 1
                self.ns[b] -= 1
                tot -= 2
                ans.append((a, b))
        return ans

    def test(self, steps):
        for step in steps:
            a, b = step
            if a != -1:
                self.nsbk[a] -= 1
            if b != -1:
                self.nsbk[b] -= 1

            if max(self.nsbk) * 2 > sum(self.nsbk):
                return False

        return sum(self.nsbk) == 0

if __name__ == '__main__':
    s = Solution([2, 2])
    assert s.test(s.solve())

    s = Solution([3, 2, 2])
    assert s.test(s.solve())

    s = Solution([1, 1, 2])
    assert s.test(s.solve())

    s = Solution([2, 3, 1])
    assert s.test(s.solve())

    import random
    for i in xrange(100):
        n = random.randint(1, 26)
        while True:
            ns = [random.randint(0, 10) for i in xrange(n)]
            if max(ns) * 2 <= sum(ns):
                break
        s = Solution(ns)
        assert s.test(s.solve())

    T = int(raw_input())
    for case_ in xrange(T):
        n = int(raw_input())
        ns = map(int, raw_input().split())
        s = Solution(ns)

        steps = s.solve()
        assert s.test(steps)

        print 'Case #%d:' % (case_ + 1),

        for step in steps:
            a, b = step
            s = ''
            if a != -1:
                s += chr(ord('A') + a)

            if b != -1:
                s += chr(ord('A') + b)

            print s,
        print ''


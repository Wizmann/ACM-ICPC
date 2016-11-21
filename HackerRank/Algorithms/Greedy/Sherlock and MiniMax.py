INF = 10 ** 10

class Solution(object):
    def __init__(self):
        self.ans = -INF
        self.value = INF

    def find_min(self, l, r, v):
        u = min(abs(l - v), abs(r - v))
        if u > self.ans:
            self.ans = u
            self.value = v
        elif u == self.ans:
            self.value = min(self.value, v)

    def solve(self, n, ns, p, q):
        ns = sorted(list(set(ns + [-INF, INF])))
        n = len(ns)

        for i in xrange(n - 1):
            a, b = ns[i], ns[i + 1]
            mid1 = (a + b) / 2
            mid2 = (a + b) / 2 + 1

            if p <= mid1 <= q:
                self.find_min(a, b, mid1)

            if p <= mid2 <= q:
                self.find_min(a, b, mid2)

            if a <= p <= b:
                self.find_min(a, b, p)

            if a <= q <= b:
                self.find_min(a, b, q)

        return self.value

assert Solution().solve(5, [38, 50, 60, 30, 48], 23, 69) == 69
assert Solution().solve(3, [5, 8, 14], 4, 9) == 4

if __name__ == '__main__':
    n = int(raw_input())
    ns = map(int, raw_input().split())
    p, q = map(int, raw_input().split())

    print Solution().solve(n, ns, p, q)

import heapq

MAXI = 10 ** 30

class Solution(object):
    def __init__(self, x, y, l, r):
        self.x = x
        self.y = y
        self.l = l
        self.r = r

    def init(self, v):
        d = {}
        vv = 1
        idx = 0
        while vv <= MAXI:
            d[idx] = vv
            vv *= v
            idx += 1
        return d


    def solve(self):
        dx = self.init(self.x)
        dy = self.init(self.y)

        l, r = self.l, self.r

        pq = [(1, 0, 0)]
        years = []

        while pq:
            cur = heapq.heappop(pq)
            years.append(cur)

            v, x, y = cur

            if v > r:
                break

            next1 = (dx[x + 1] + dy[y], x + 1, y)
            next2 = (dx[x] + dy[y + 1], x, y + 1)

            if next1 not in pq:
                heapq.heappush(pq, next1)
            if next2 not in pq:
                heapq.heappush(pq, next2)

        g = 0
        years = [0] + map(lambda x: x[0], years)
        m = len(years)
        for i in xrange(m - 1):
            a, b = years[i] + 1, years[i + 1] - 1
            if a > r:
                continue
            elif b < l:
                continue
            elif a <= l and b <= r:
                g = max(g, b - l + 1)
            elif l <= a and b <= r:
                g = max(g, b - a + 1)
            elif l <= a and r <= b:
                g = max(g, r - a + 1)
            elif a <= l and r <= b:
                g = max(g, r - l + 1)
            else:
                assert False
        return g

assert Solution(2, 3, 1, 10).solve() == 1
assert Solution(3, 5, 10, 22).solve() == 8
assert Solution(2, 3, 3, 5).solve() == 0

if __name__ == '__main__':
    (x, y, l, r) = map(int, raw_input().split())
    print Solution(x, y, l, r).solve()

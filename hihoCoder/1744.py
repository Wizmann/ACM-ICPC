class Solution(object):
    def __init__(self, n, x, y, z):
        self.n = n
        self.x = x
        self.y = y
        self.z = z

    def calc(self, u):
        cash = u * self.z
        vcnt = self.n - u

        if cash <= vcnt * (self.x - self.y):
            if self.x == self.y:
                return vcnt
            else:
                return 1.0 * cash / (self.x - self.y)
        else:
            res = vcnt
            cash -= vcnt * (self.x - self.y)
            res += 1.0 * cash / self.x
            return res

    def solve(self):
        l, r = 0, self.n
        res = 0
        idx = -1
        while l <= r:
            lt, rt = l + (r - l) / 3, l + 2 * (r - l) / 3

            vlt, vrt = map(self.calc, [lt, rt])
            res = max(res, vlt, vrt)

            if vlt > vrt:
                r = rt - 1
            else:
                l = lt + 1

        return int(res)

    def brute_force(self):
        res = 0
        maxi = -1
        for i in xrange(self.n + 1):
            if self.calc(i) > res:
                maxi = i
                res = self.calc(i)
        return int(res)

assert Solution(12, 612, 389, 25).solve() == 1

from random import randint
for i in xrange(1, 100):
    n = randint(1, 100)
    x = randint(1, 1000)
    y = randint(1, x)
    z = randint(1, 1000)
    S = Solution(n, x, y, z)
    #print S.brute_force(), S.solve()
    assert S.brute_force() == S.solve()

if __name__ == '__main__':
    (n, x, y, z) = map(int, raw_input().split())

    print Solution(n, x, y, z).solve()


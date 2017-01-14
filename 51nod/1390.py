class Solution(object):
    def calc_n(self, s):
        l, r = 0, 10 ** 15
        while l <= r:
            m = (l + r) >> 1
            tot = 2 * (1 + m) * m / 2 - m
            if tot > s:
                r = m - 1
            else:
                l = m + 1
        tot = 2 * (1 + r) * r / 2 - r
        if tot != s:
            return -1
        return r
        
    def solve(self, a, b):
        n = self.calc_n(a + b)
        if n == 0:
            return 0
        if n == -1:
            return -1

        maxi = 2 * n - 1
        cnt = 0

        while a > 0 and maxi > 0:
            #print a, maxi, cnt
            if a % 2 == 1:
                if a <= maxi:
                    a = 0
                else:
                    if a == maxi + 2:
                        a -= maxi - 2
                        maxi = maxi - 4
                    else:
                        a -= maxi
                        maxi -= 2
            else:
                if a <= maxi:
                    maxi = a - 3
                    a -= a - 1
                else:
                    a -= maxi
                    maxi -= 2
            cnt += 1

        if a != 0:
            return -1
        return cnt

assert Solution().calc_n(1) == 1
assert Solution().calc_n(2) == -1
assert Solution().calc_n(25) == 5
assert Solution().solve(8, 17) == 2
assert Solution().solve(17, 8) == 3
assert Solution().solve(0, 0) == 0
assert Solution().solve(1000000000000, 0) == 1000000
assert Solution().solve(1, 999999999999) == 1
assert Solution().solve(2000001, 999997999999) == 3

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        (a, b) = map(int, raw_input().split())
        print Solution().solve(a, b)

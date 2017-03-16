class Solution(object):
    def __init__(self, n, m):
        self.n = n
        self.m = min(n - 1, m)

    def solve(self):
        if self.n == 1:
            return 1

        l = 1
        r = 10 ** 20

        while l <= r:
            mid = (l + r) >> 1
            if self.eaten(mid):
                r = mid - 1
            else:
                l = mid + 1

        return l


    def eaten(self, mid):
        day = self.m
        if mid < day:
            return False

        a = self.n + (mid - day) * self.m 
        b = (day + mid) * (mid - day + 1) / 2

        return a <= b

    def simulate(self):
        day = 1
        cur = self.n
        while True:
            cur = min(self.n, cur + self.m)
            cur = max(0, cur - day)

            if cur == 0:
                return day

            day += 1



if __name__ == '__main__':
    assert Solution(5, 2).eaten(1) == False
    assert Solution(5, 2).eaten(2) == False
    assert Solution(5, 2).eaten(3) == False
    assert Solution(5, 2).eaten(4) == True
    assert Solution(5, 2).eaten(5) == True

    assert Solution(5, 2).eaten(123456) == True

    assert Solution(5, 4).solve() == 5

    assert Solution(5, 2).solve() == 4
    assert Solution(8, 1).solve() == 5


    assert Solution(1, 1).solve() == 1
    assert Solution(2, 1).solve() == 2
    assert Solution(2, 2).solve() == 2
    assert Solution(2, 3).solve() == 2
    assert Solution(5, 2).solve() == 4
    assert Solution(8, 1).solve() == 5



    (a, b) = map(int, raw_input().split())
    print Solution(a, b).solve()

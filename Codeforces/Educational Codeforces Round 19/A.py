class Solution(object):
    def __init__(self, n, k):
        self.n = n
        self.k = k

    def solve(self):
        i = 2
        res = []
        while i * i <= self.n:
            while self.n % i == 0:
                res.append(i)
                self.n /= i
            i += 1

        if self.n != 1:
            res.append(self.n)
        
        if len(res) < self.k:
            return []
        else:
            a = res[:self.k - 1]
            b = [reduce(lambda x, y: x * y, res[self.k - 1:])]
            return a + b

assert Solution(5, 1).solve() == [5]
assert Solution(5, 2).solve() == []
assert Solution(14, 3).solve() == []
assert Solution(1024, 5).solve() == [2, 2, 2, 2, 64]

if __name__ == '__main__':
    (n, k) = map(int, raw_input().split())
    res = Solution(n, k).solve()
    if not res:
        print -1
    else:
        print ' '.join(map(str, res))

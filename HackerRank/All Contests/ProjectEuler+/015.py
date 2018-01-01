MOD = (10 ** 9) + 7

def solve(n, m):
    res = 1
    for i in xrange(min(n, m)):
        res *= (n + m - i)
        res /= i + 1
    return res % MOD

if __name__ == '__main__':
    T = int(raw_input())

    for case_ in xrange(T):
        n, m = map(int, raw_input().split())
        print solve(n, m)

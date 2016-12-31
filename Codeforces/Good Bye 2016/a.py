def solve(n, k):
    tot = 4 * 60 - k
    for i in xrange(1, n + 1):
        tot -= 5 * i
        if tot < 0:
            return i - 1
    return n

assert solve(3, 222) == 2
assert solve(4, 190) == 4
assert solve(7, 1) == 7

if __name__ == '__main__':
    (n, k) = map(int, raw_input().split())
    print solve(n, k)

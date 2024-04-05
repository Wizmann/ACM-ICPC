# coding=utf-8
INF = 10 ** 10

def solve(n):
    for i in xrange(1, n / 2 + 2):
        if n % i == 0 and (n / i) % 2 == 1:
            m = (n / i) / 2
            l = i - m
            r = i + m

            if l > 0:
                assert (l + r) * (r - l + 1) / 2 == n
                yield l, r

        if n % (i + i + 1) == 0:
            m = n / (i + i + 1)
            l = i - m + 1
            r = i + 1 + m - 1

            if l > 0:
                assert (l + r) * (r - l + 1) / 2 == n
                yield l, r

assert list(solve(10)) == [(1, 4)]

n = int(raw_input())

for (a, b) in solve(n):
    print a, b

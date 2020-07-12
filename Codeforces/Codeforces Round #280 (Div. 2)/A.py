def solve(n):
    tot = 0
    cur = 1
    delta = 1
    for i in xrange(1, 1000):
        tot += (1 + i) * i / 2
        if tot > n:
            return i - 1

assert solve(25) == 4

if __name__ == '__main__':
    n = int(raw_input())
    print solve(n)

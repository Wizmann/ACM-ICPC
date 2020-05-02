def solve(x):
    cur = 100
    for i in xrange(10000):
        if cur >= x:
            return i
        cur = int(cur * 1.01)
    return -1

assert solve(103) == 3
assert solve(101) == 1
assert solve(10 ** 18) != -1
assert solve(1000000000000000000) == 3760


x = int(raw_input())
print solve(x)

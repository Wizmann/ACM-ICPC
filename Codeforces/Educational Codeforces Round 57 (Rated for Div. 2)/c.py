def solve(u):
    for i in xrange(3, 400):
        if (u * i) % 180 == 0 and u * i / 180 < i - 1:
            return i
    return -1

T = int(raw_input())

assert solve(54) == 10

for i in xrange(T):
    u = int(raw_input())
    print solve(u)

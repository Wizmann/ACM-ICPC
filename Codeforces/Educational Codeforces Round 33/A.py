def solve(ns):
    u = 3
    for num in ns:
        if num == u:
            return False
        u = 1 + 2 + 3 - u - num
    return True

assert solve([1, 1, 2]) == True
assert solve([1, 2]) == False

n = int(raw_input())
ns = map(int, [raw_input() for i in xrange(n)])
print 'YES' if solve(ns) else 'NO'

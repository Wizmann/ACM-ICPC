def solve(n):
    res = []
    while n > 1:
        res.append(1)
        n -= 2
    if n == 1:
        res[0] = 7
    return ''.join(map(str, res))
 
assert solve(3) == '7'
assert solve(2) == '1'
assert solve(4) == '11'
 
T = int(raw_input())
 
for case_ in xrange(T):
    n = int(raw_input())
    print solve(n)

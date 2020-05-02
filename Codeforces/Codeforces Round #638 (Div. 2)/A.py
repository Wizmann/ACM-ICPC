def solve(n):
    left = (1 << n)
    right = left - 2
 
    for i in xrange(1, n / 2):
        left += 1 << i
        right -= 1 << i
    # print left, right
    return abs(left - right)
 
assert solve(2) == 2
assert solve(4) == 6
 
T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
    print solve(n)

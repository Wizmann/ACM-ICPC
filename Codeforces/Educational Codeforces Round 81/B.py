
from collections import defaultdict
 
def solve(s, x):
    remains = defaultdict(int)
    remains[0] = 1
    s = map(int, s)
    b = 0
    for num in s:
        if num == 0:
            b += 1
        else:
            b -= 1
        remains[b] += 1
    remains[b] -= 1
 
    res = 0
    for r, c in remains.items():
        y = x - r
        if b == 0:
            if y == 0:
                return -1
        elif y % b == 0 and y / b >= 0:
            res += c
    return res
 
assert solve('010010', 10) == 3
assert solve('10101', 3) == 0
assert solve('0', 0) == 1
assert solve('01', 0) == -1
 
T = int(raw_input())
 
for case_ in xrange(T):
    n, x = map(int, raw_input().split())
    s = raw_input()
    print solve(s, x)

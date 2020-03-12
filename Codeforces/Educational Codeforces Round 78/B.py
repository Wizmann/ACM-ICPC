INF = 10 ** 10
 
def solve(d):
    if d == 0:
        return 0
 
    l, r = 1, INF
    while l <= r:
        m = (l + r) / 2
        if (1 + m) * m / 2 >= d:
            r = m - 1
        else:
            l = m + 1
    b = l
    tot = (1 + b) * b / 2
    #print tot, b, d
    if tot == d:
        return b
    elif tot % 2 == d % 2:
        return b
    else:
        if (b + 1) % 2 == 0:
            return b + 2
        else:
            return b + 1
import copy
def brute_force(delta):
    if delta == 0:
        return 0
    d = {delta: 0}
    for i in xrange(1, 100):
        dd = {}
        for key, value in d.items():
            value += 1
 
            key1 = abs(key + i)
            #print key1, value
            if key1 not in dd:
                dd[key1] = value
 
            if key1 == 0:
                return value
 
            key2 = abs(key - i)
            #print key2, value
            if key2 not in dd:
                dd[key2] = value
 
            if key2 == 0:
                return value
        d = dd
 
assert solve(2) == 3
assert solve(3) == 2
assert solve(5) == 5
 
 
'''
for i in xrange(20):
    mini = INF
    print i, brute_force(i), solve(i)
    assert solve(i) == brute_force(i)
'''
 
assert solve(1) == 1
assert solve(4) == 3
assert solve(6) == 3
assert solve(0) == 0
assert solve(10) == 4
assert solve(8) == 4
assert solve(9) == 5
 
if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        (a, b) = map(int, raw_input().split())
        print solve(abs(a - b))

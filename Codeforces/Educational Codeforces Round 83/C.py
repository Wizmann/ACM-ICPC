# https://codeforces.com/contest/1312/problem/C

def tok(k, num):
    res = []
    while num:
        if num % k == 0:
            res.append(0)
        elif num % k == 1:
            res.append(1)
        else:
            return -1
        num /= k
    u = 0
    for num in res[::-1]:
        u = u * 2 + num
    return u
 
assert tok(9, 810) == 4 + 8
assert tok(2, 1) == 1
assert tok(2, 3) == 3
assert tok(2, 100) == 100
 
def solve(n, k, ns):
    st = set()
    ms = []
    for num in ns:
        if num == 0:
            continue
        u = tok(k, num)
        if u == -1:
            return False
        ms.append(u)
    m = len(ms)
    for i in xrange(m):
        for j in xrange(i + 1, m):
            if (ms[i] & ms[j]) != 0:
                return False
    return True
 
assert solve(4, 100, [0, 0, 0, 0])
 
T = int(raw_input())
for case_ in xrange(T):
    (n, k) = map(int, raw_input().split())
    ns = map(int, raw_input().split())
    print 'YES' if solve(n, k, ns) else 'NO'

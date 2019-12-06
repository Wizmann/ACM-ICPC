import sys
def do_solve(pre, ns):
    assert len(ns) == 4
    cur = -1
    for i in xrange(4):
        if ns[i] != 0:
            cur = i
            break
    if cur == -1:
        return []
 
    if pre + 1 >= 4 or ns[pre + 1] == 0:
        return None
 
    a = ns[cur]
    b = 0 if cur + 1 >= 4 else ns[cur + 1]
 
    if cur == pre + 1:
        b -= a - 1
        if b < 0:
            return None
        nxt = ns[:]
        nxt[cur] = 0
        if cur + 1 < 4:
            nxt[cur + 1] = b
        res = do_solve(cur, nxt)
        if res is None:
            return None
        res = [cur, cur + 1] * (a - 1) + [cur] + res
        return res
    elif cur == pre:
        b -= a
        if b < 0:
            return None
        nxt = ns[:]
        nxt[cur] = 0
        if cur + 1 < 4:
            nxt[cur + 1] = b
        res = do_solve(cur, nxt)
        if res is None:
            return None
        res = [cur + 1, cur] * a + res
        return res
    else:
        return None
 
def solve(ns):
    for i in [-1, 0, 1, 2, 3, 4]:
        res = do_solve(i, ns)
        if res is not None:
            return res
    return None
 
'''
print solve([2, 2, 2, 1])
print solve([1, 2, 3, 4])
print solve([2, 2, 2, 3])
print solve([2, 100, 100, 3])
print solve([2, 100, 100, 2])
'''
 
(a, b, c, d) = map(int, raw_input().split())
try:
    res = solve([a, b, c, d])
    if res is None:
        print 'NO'
    else:
        print 'YES'
        print ' '.join(map(str, res))
except:
    print 'NO'

MAXN = 10000

def getitem(s):
    for x in s:
        return x

def solve(k, ns):
    n = len(ns)
    st = set(ns)
    if len(st) > k:
        return []

    p = 0
    nums = set(ns)
    for i in xrange(1, k + 1):
        if len(nums) < k and i not in nums:
            nums.add(i)

    nums = list(nums)
    res = nums * n

    return res

def check(k, ns):
    ns = solve(k, ns)
    n = len(ns)
    u = sum(ns[:k])
    for i in xrange(n - k):
        assert u == sum(ns[i: i + k])
    return True


assert check(2, [2, 2, 2, 3])
assert check(4, [4, 3, 4, 2])
assert check(3, [1, 2, 2, 1])
assert check(2, [1, 2, 2, 1])
assert solve(2, [1, 2, 3]) == []
assert check(100, [1 for i in xrange(100)])

import random
for i in xrange(10):
    k = 100
    ns = [i + 1 for i in xrange(100)]
    assert check(k, ns)

T = int(raw_input())
for case_ in xrange(T):
    n, k = map(int, raw_input().split())
    ns = map(int, raw_input().split())
    res = solve(k, ns)
    if not res:
        print -1
    else:
        print len(res)
        print ' '.join(map(str, res))

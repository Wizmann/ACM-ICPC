def getitem(s):
    for x in s:
        return x
 
def solve(k, ns):
    n = len(ns)
    st = set(ns)
    if len(st) > k:
        return []
 
    res = []
    maxi = max(max(ns), k)
 
    p = 0
    nums = set(ns)
    for i in xrange(1, k + 1):
        if len(nums) < k and i not in nums:
            nums.add(i)
 
    while p < n:
        if ns[p] in nums:
            nums.remove(ns[p])
            res.append(ns[p])
            p += 1
        else:
            cur = getitem(nums)
            nums.remove(cur)
            res.append(cur)
 
        if not nums:
            nums.add(res[-k])
 
    return res
 
def check(k, ns):
    ns = solve(k, ns)
    assert len(ns) <= 10000
    n = len(ns)
    mp = {}
    idx = 1
    for num in ns:
        if num not in mp:
            mp[num] = idx
            idx += 1
 
    ns = map(lambda x: mp[x], ns)
    for i in xrange(n - k):
        st = set(ns[:i + k])
        assert st == set(range(1, k + 1))
    return True
 
 
assert check(2, [2, 2, 2, 3])
assert check(4, [4, 3, 4, 2])
assert check(3, [1, 2, 2, 1])
assert check(2, [1, 2, 2, 1])
assert solve(2, [1, 2, 3]) == []
 
'''
import random
for i in xrange(10):
    k = 100
    ns = [random.choice(range(1, k + 1)) for i in xrange(100)]
    assert check(k, ns)
'''
 
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

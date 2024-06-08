#python3
#coding=utf-8

import sys
if sys.version_info[0] == 3:
    raw_input = input
    xrange = range
    map_ = map
    def map(*args, **kwargs):
        return list(map_(*args, **kwargs))

MAXI = 1234567

n = int(raw_input())
ns = map(int, raw_input().split())

assert(n == len(ns))

ns.sort()

presum = [0 for i in xrange(MAXI)]

for num in ns:
    presum[num] += 1

for i in xrange(1, MAXI):
    presum[i] += presum[i - 1]

# print(presum)

d = {}
res = 0
for num in ns:
    if num in d:
        d[num] -= 1
        res += d[num]
        continue
    cur = 0
    for i in xrange(1, (MAXI - 1) // num + 1):
        l = (num * i) - 1
        r = min(MAXI - 1, num * (i + 1) - 1)
        # print(num, i, l, r, presum[r], presum[l])
        cur += i * (presum[r] - presum[l])
    cur -= 1
    # print(num, cur)
    d[num] = cur
    res += cur
print(res)

'''

^^^TEST^^^^
3
3 1 4
----------
8
$$$$TEST$$$$$

^^^TEST^^^^
4
3 1 1 4
----------
16
$$$$TEST$$$$$

^^^TEST^^^^
6
3 3 1 4 1 4
----------
35
$$$$TEST$$$$$

^^^TEST^^^^
6
2 7 1 8 2 8
----------
53
$$$$TEST$$$$$

^^^TEST^^^^
12
3 31 314 3141 31415 314159 2 27 271 2718 27182 271828
----------
592622
$$$$TEST$$$$$

^^^TEST^^^^
9
11 33 33 222 444 444 1 2 3
----------
2356
$$$$TEST$$$$$

^^^TEST^^^^
11
11 33 33 222 444 444 1 2 3 1000000 99999
----------
2195603
$$$$TEST$$$$$
'''





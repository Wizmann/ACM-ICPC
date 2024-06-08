#python3
#coding=utf-8

MOD = 998244353

import sys
if sys.version_info[0] == 3:
    raw_input = input
    xrange = range
    map_ = map
    def map(*args, **kwargs):
        return list(map_(*args, **kwargs))

(n, m) = map(int, raw_input().split())

res = 0
for i in xrange(80):
    cur = 1 << i
    if (m & cur) == 0:
        continue
    res += cur * ((n + 1) // (cur * 2))
    res += max(0, ((n + 1) % (cur * 2) - cur))
    # print(res)

# print(res)
print(res % MOD)


'''
^^^^^TEST^^^^
3 3
------
4
$$$$TEST$$$$

^^^^^TEST^^^^
4 3
------
4
$$$$TEST$$$$

^^^^^TEST^^^^
0 0
------
0
$$$$TEST$$$$

^^^^^TEST^^^^
1152921504606846975 1152921504606846975
------
499791890
$$$$TEST$$$$
'''

#python3
#coding=utf-8

import sys
import io

if sys.implementation.name == "pypy":
    import atexit

    original_stdout = sys.stdout
    original_stdin = sys.stdin

    if sys.version_info[0] == 2:  # PyPy2
        sys.stdout = io.BytesIO()
        sys.stdin = io.BytesIO(sys.stdin.read())
    else:  # PyPy3
        sys.stdout = io.StringIO()
        sys.stdin = io.StringIO(sys.stdin.read())

    def flush_stdout():
        original_stdout.write(sys.stdout.getvalue())
        original_stdout.flush()

    atexit.register(flush_stdout)
    input = lambda: sys.stdin.readline().rstrip()

if sys.version_info[0] == 3:
    raw_input = input
    xrange = range
    map_ = map
    sorted_ = sorted
    def map(*args, **kwargs):
        return list(map_(*args, **kwargs))
    def sorted(*args, **kwargs):
        return list(sorted_(*args, **kwargs))

n, k = map(int, raw_input().split())
ns = map(int, raw_input().split())

ns = sorted(enumerate(ns), key=lambda p: p[1])
ans = [0] * n

for i in xrange(n - 2, -1, -1):
    preidx, pre = ns[i + 1]
    curidx, cur = ns[i]

    if pre == cur:
        ans[curidx] = ans[preidx]
    elif pre - cur <= k:
        ans[curidx] = ans[preidx] + 1
    else:
        ans[curidx] = max(0, ans[preidx] + 1 + ((cur - pre + k) // k))

for item in ans:
    print(item, end=' ')
print()

'''
^^^^^^^^TEST^^^
3 1
1 3 4
-----------
1 1 0
$$$$TEST$$$$$

^^^^^^^^TEST^^^
6 2
1 2 5 6 7 8
-----------
4 3 3 2 1 0
$$$$TEST$$$$$

^^^^^^^^TEST^^^
8 10
1 14 5 14 19 19 8 10
-----------
5 1 4 1 0 0 3 2
$$$$TEST$$$$$

^^^^^^^^TEST^^^
2 1
2 1
-----------
0 1
$$$$TEST$$$$$

^^^^^^^^TEST^^^
2 2
2 1
-----------
0 1
$$$$TEST$$$$$

^^^^^^^^TEST^^^
2 123456
2 1
-----------
0 1
$$$$TEST$$$$$

^^^^^^^^TEST^^^
3 123456
2 1 3
-----------
1 2 0
$$$$TEST$$$$$

^^^^^^^^TEST^^^
3 2
1 3 5
-----------
2 1 0
$$$$TEST$$$$$

^^^^^^^^TEST^^^
4 2
1 4 5 123456
-----------
1 1 0 0
$$$$TEST$$$$$
'''

#coding=utf-8

import sys
import io

if sys.implementation.name == "pypy":
    import atexit
    original_stdout = sys.stdout
    buffer = io.StringIO()
    sys.stdout = buffer

    def flush_stdout():
        original_stdout.write(buffer.getvalue())
        original_stdout.flush()

    atexit.register(flush_stdout)

    sys.stdin = io.StringIO(sys.stdin.read())
    input = lambda: sys.stdin.readline().rstrip()

INF = 10 ** 100

import sys
if sys.version_info[0] == 3:
    raw_input = input
    xrange = range
    map_ = map
    def map(*args, **kwargs):
        return list(map_(*args, **kwargs))


(n, q) = map(int, raw_input().split())

ns = [0] + map(int, raw_input().split())
for i in xrange(1, n + 1):
    ns[i] += ns[i - 1]

for case_ in xrange(q):
    (l, r, k) = map(int, raw_input().split())
    m = r - l + 1
    cnt1 = ns[r] - ns[l - 1]
    cnt0 = m - cnt1

    mini = INF
    if 1 + k == m:
        mini = min(mini, cnt0)

    diff = k - cnt1
    # print case_, diff, cnt0, cnt1
    if diff > 0 and cnt0 > diff:
        mini = min(mini, diff)
    if diff < 0 and cnt1 >= abs(diff):
        mini = min(mini, abs(diff))
    if diff == 0 and cnt0:
        mini = min(mini, 0)

    if mini >= INF:
        mini = -1
    print(mini)

'''
^^^^^TEST^^^^^
5 4
0 0 1 0 1
1 3 2
2 4 0
3 5 2
1 1 1
----------------
1
1
0 
-1
$$$$TEST$$$$$


^^^^^TEST^^^^^
8 3
1 1 1 1 1 1 1 1
2 6 2
5 8 2
1 8 7
----------------
3
2
0
$$$$TEST$$$$$
'''

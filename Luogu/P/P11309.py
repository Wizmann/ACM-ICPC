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

T = int(raw_input())

for case_ in xrange(T):
    n, k = map(int, raw_input().split())
    ns = map(int, raw_input().split())

    if k == 0:
        pass
    elif n == 2:
        if k % 2:
            ns = ns[::-1]
    else:
        ns.sort(reverse=True)

    maxi = -1
    ans = 0
    # print(ns)
    for i in xrange(n):
        maxi = max(maxi, ns[i])
        ans += maxi
    print(ans)

'''
^^^^^TEST^^^^
3
3 0
9 8 2
2 1
10 11
5 10
1 2 3 4 5
-----------
27
22
25
$$$$TEST$$$$

^^^TEST^^^
5
5 0
100 101 102 103 104
5 1
20 40 50 70 10
2 103
30 20
7 2
1 2 3 4 5 6 7
2 10
1 1
----------
510
350
50
49
2
$$$$$TEST$$$

^^^^^TEST^^^^
4
3 1
9 8 2
3 1
1 8 2
3 2
1 8 2
2 2
1 8
-----------
27
24
24
9
$$$$TEST$$$$

'''


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

n = int(raw_input())
ns = map(int, raw_input().split())

res = min(ns) * (n - 1) + ns[-1]

for i in xrange(min(ns) + 1, ns[-1] + 1):
    for j in xrange(n - 2, -1, -1):
        if i <= ns[j]:
            res += 1
        else:
            break
print(res)


'''
^^^^^TEST^^^^
2
1 2
--------
3
$$$$TEST$$$$

^^^^^TEST^^^^
6
1 1 4 5 1 4
--------
9
$$$$TEST$$$$

^^^^^TEST^^^^
5
2 2 2 2 2
--------
10
$$$$TEST$$$$

^^^^^TEST^^^^
5
2 2 2 4 4
--------
14
$$$$TEST$$$$

'''

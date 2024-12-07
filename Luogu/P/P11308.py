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
    (n, m, k, p) = map(int, raw_input().split())

    maxi = m - p // n
    mini = m - p % n
    if (p + m - 1) // m <= n - 1:
        mini = m
    if k <= maxi:
        print('Together')
    elif k > mini:
        print('Divide')
    else:
        print('Chance')

'''
^^^^^TEST^^^^^
10
3 3 3 1
3 3 4 5
4 4 4 12
4 4 3 8
10 10 7 34
10 10 8 34
12 11 11 12
12 11 12 12
9 9 1 80
9 9 6 70
---------------
Together
Divide
Chance
Chance
Together
Chance
Chance
Divide
Together
Chance
$$$$$$$$$TEST$$$

^^^^TEST^^^
6
1 1 1 0
2 1 1 0
2 1 1 1
2 2 1 3
2 2 2 2
3 2 3 2
---------
Together
Together
Together
Together
Chance
Divide
$$$TEST$$$$
'''



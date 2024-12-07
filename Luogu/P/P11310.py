#python3
#coding=utf-8

import sys
import io

if hasattr(sys, 'implementation') and sys.implementation.name == "pypy":
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

def solve(r):
    if r == 0:
        return -1
    r = r * 2 + 1
    cnt = 0
    while True:
        cnt += 1
        r = r * (r + 1) // 2
        if r % 2 == 0:
            break
    return cnt

def solve2(r):
    if r == 0:
        return -1
    elif r % 2:
        return 1
    else:
        cnt = 1
        while r % 2 == 0:
            cnt += 1
            r //= 2
        return cnt

for i in xrange(0, 1000):
    # print(i, solve(i), solve2(i))
    assert(solve(i) == solve2(i))

for i in [100, 114514, 12345, 12345678901234567, 123456789012345678]:
    # print(i, solve(i), solve2(i))
    assert(solve(i) == solve2(i))

T = int(raw_input())
for case_ in xrange(T):
    r = int(raw_input())
    ans = solve2(r)
    if ans == -1:
        print('NO!')
    else:
        print(ans)

'''
^^^^TEST^^^^
5
2
4
6
8
10
-------
2
3
2
4
2
$$$TEST$$$

^^^^TEST^^^^
2
4
0
-----------
3
NO!
$$$$TEST$$$$
'''

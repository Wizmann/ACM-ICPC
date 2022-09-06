#python3
#coding=utf-8

T = int(input())

for case_ in range(T):
    n, x, y = map(int, input().split())

    tot = (1 + n) * n // 2

    vx = tot // (x + y) * x
    vy = tot // (x + y) * y

    if vx + vy != tot:
        print('Case #%d: IMPOSSIBLE' % (case_ + 1))
        continue

    res = []
    cur = n
    while vx:
        cur = min(cur, vx)
        if vx >= cur:
            res.append(cur)
            vx -= cur
            cur = min(cur - 1, vx)
    assert(sum(res) == tot - vy)
    print("Case #%d: POSSIBLE" % (case_ + 1))
    print(len(res))
    print(' '.join(map(str, res)))

'''
^^^^TEST^^^^
3
3 1 2
3 1 1
3 1 3
---------
Case #1: POSSIBLE
1
2
Case #2: POSSIBLE
2
1 2
Case #3: IMPOSSIBLE
$$$$TEST$$$$

^^^^TEST^^^^
2
1000 2 3
1000 1 500499
----------
<IGNORE>
<IGNORE>
$$$TEST$$$
'''



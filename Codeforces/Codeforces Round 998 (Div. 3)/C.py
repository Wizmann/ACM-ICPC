from collections import Counter

MAXI = 212345

T = int(raw_input())

for case_ in xrange(T):
    n, k = map(int, raw_input().split())
    ns = [0 for i in xrange(k + 1)]
    for num in map(int, raw_input().split()):
        if num <= k:
            ns[num] += 1

    score = 0

    for key in xrange(k + 1):
        cur = ns[key]
        if not cur:
            continue
        nxt = ns[k - key]
        if not nxt:
            continue
        if key * 2 < k:
            delta = min(cur, nxt)
            score += delta
            ns[key] -= delta
            ns[k - key] -= delta
        elif key * 2 == k:
            delta = cur / 2
            score += delta
            ns[key] -= delta * 2
        else:
            break
    print score

'''
^^^^TEST^^^^
4
4 4
1 2 3 2
8 15
1 2 3 4 5 6 7 8
6 1
1 1 1 1 1 1
16 9
3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3
------------
2
1
0
4
$$$$TEST$$$$
'''


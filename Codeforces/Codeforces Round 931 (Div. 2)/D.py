#python2

def setBitNumber(n):
    n |= n>>1
    n |= n>>2  
    n |= n>>4 
    n |= n>>8
    n |= n>>16
    n |= n>>32
    n = n + 1
    return (n >> 1)
 
# This code is contributed
# by Anant Agarwal.

def solve(cur, target):
    res = []

    if target > cur:
        return []

    for i in xrange(63):
        if cur == target:
            res.append(target)
            break
        if cur == setBitNumber(cur):
            return []
        if setBitNumber(cur) == setBitNumber(target):
            res.append(cur)
            res.append(target)
            break
        nxt1 = cur ^ setBitNumber(cur)
        nxt1 = setBitNumber(nxt1) - 1 + setBitNumber(nxt1)
        nxt2 = cur ^ nxt1
        # print cur, nxt1, nxt2
        res.append(cur)
        cur = nxt1

    return res


T = int(raw_input())

for case_ in xrange(T):
    a, b = map(int, raw_input().split())
    res = solve(a, b)
    if not res:
        print -1
    else:
        print len(res) - 1
        print ' '.join(map(str, res))

'''
^^^^^TEST^^^
3
7 3
4 2
481885160128643072 45035996273704960
-------------
1
7 3
-1
3
481885160128643072 337769972052787200 49539595901075456 45035996273704960
$$$TEST$$$$

^^^^TEST^^^^
5
2 1
3 1
3 2
5 1
5 2
--------
<ignore>
$$$TEST$$$
'''

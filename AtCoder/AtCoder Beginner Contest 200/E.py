#coding=utf-8

def solve(n, k):
    tot = 0
    pre = 0
    p = -1
    for i in xrange(3, n * 3 + 1):
        a = max(2, i - n)
        b = min(2 * n, i - 1)

        if a > n:
            a = n - (a - n) + 1
            b = n - (b - n) + 1
            tot += (b + a) * (a - b + 1) / 2
        elif b <= n:
            a -= 1
            b -= 1
            tot += (a + b) * (b - a + 1) / 2
        else:
            a -= 1
            tot += (a + n - 1) * (n - 1 - a + 1) / 2
            b = n - (b - n) + 1
            tot += (b + n) * (n - b + 1) / 2


        if tot >= k:
            p = i
            break
        pre = tot
    # print tot
    tot2 = 0
    pre2 = 0
    res = []
    # print p, tot
    for i in xrange(max(1, p - 2 * n), p - 1):
        mini = max(1, p - i - n)
        maxi = min(n, p - i - 1)
        tot2 += maxi - mini + 1
        if tot2 >= k - pre:
            res.append(i)
            break
        pre2 = tot2
    rem = k - pre - pre2
    mini = max(1, p - res[0] - n)
    res.append(rem + mini - 1)
    res.append(p - sum(res))
    return res


n, k = map(int, raw_input().split())

res = solve(n, k)
print ' '.join(map(str, res))

'''
^^^^TEST^^^
2 5
----
1 2 2
$$$TEST$$$

^^^^TEST^^^
2 8
----
2 2 2
$$$TEST$$$

^^^^TEST^^^
2 1
----
1 1 1
$$$TEST$$$

^^^^TEST^^^
2 2
----
1 1 2
$$$TEST$$$

^^^^TEST^^^
2 3
----
1 2 1
$$$TEST$$$

^^^^TEST^^^
2 4
----
2 1 1
$$$TEST$$$

^^^TEST^^^
9 47
---
3 1 4
$$$TEST$$$

^^^TEST^^^
1000000 1
---
1 1 1
$$$TEST$$$

^^^TEST^^^
1000000 5
---
1 1 3
$$$TEST$$$

^^^TEST^^^
1000000 1000000000000000000
---
1000000 1000000 1000000
$$$TEST$$$

'''


#coding=utf-8

MOD = 998244353

n = int(raw_input())

ns = map(int, raw_input().split())

ns.sort()

res = 0
pre = 0

for i in xrange(n):
    res += ns[i] * pre + ns[i] * ns[i]
    res %= MOD
    pre = (pre * 2 + ns[i]) % MOD
print res

'''
^^^TEST^^^
3
2 4 3
----
63
$$$TEST$$$

^^^TEST^^^
1
10
----
100
$$$TEST$$$

^^^TEST^^^
7
853983 14095 543053 143209 4324 524361 45154
----
206521341
$$$TEST$$$


'''



#coding=utf-8

from collections import defaultdict

T = int(raw_input())

for case_ in xrange(T):
    n, m = map(int, raw_input().split())

    s = []
    for i in xrange(n):
        s.append(raw_input().strip())

    res = []
    for a in xrange(m):
        d = defaultdict(int)
        for i in xrange(n):
            for j in xrange(m):
                if j == a:
                    continue
                if s[i][j] != s[0][j]:
                    d[i] += 1
        if max(d.values() + [0]) > 1:
            continue
        d2 = defaultdict(list)
        for i in xrange(n):
            d2[s[i][a]].append(i)

        sall = set(range(n))
        s1 = set(d.keys())
        for k, l in d2.items():
            s2 = set(l)
            if (sall ^ s2) & s1:
                continue
            res = list(s[0])
            res[a] = k
            break
        if res:
            break
    if res:
        print ''.join(res)
    else:
        print -1

'''
^^^^TEST^^^
5
2 4
abac
zbab
2 4
aaaa
bbbb
3 3
baa
aaa
aab
2 2
ab
bb
3 1
a
b
c
------
abab
-1
aaa
ab
z
$$$TEST$$$
'''





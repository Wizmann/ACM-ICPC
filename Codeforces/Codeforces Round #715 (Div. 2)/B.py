def solve(s):
    s = list(s)
    n = len(s)
    tt = 0
    mm = 0

    for c in s:
        if c == 'T':
            tt += 1
        else:
            mm += 1

    if mm != n / 3:
        return False

    t2 = 0
    for i, c in enumerate(s):
        if c == 'T':
            t2 += 1
            if t2 > tt / 2:
                s[i] = 't'

    t1s = []
    t2s = []
    ms = []
    for i, c in enumerate(s):
        if c == 'T':
            t1s.append(i)
        elif c == 'M':
            ms.append(i)
        elif c == 't':
            t2s.append(i)
        else:
            assert False

    while t1s and t2s and ms:
        t2 = t2s.pop()
        m = ms.pop()
        t1 = t1s.pop()
        if not (t1 < m < t2):
            return False

    return not t1s and not t2s and not ms

T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
    s = raw_input()

    print 'YES' if solve(s) else 'NO'



'''

^^^TEST^^^
3
6
TTMTMT
6
TMTMTT
12
TTMTMTTMTMTT
----
YES
YES
YES
$$$TEST$$$


^^^TEST^^^
1
6
TTMTMT
---
YES
$$$TEST$$$

^^^TEST^^^
5
3
TMT
3
MTT
6
TMTMTT
6
TMTTTT
6
TTMMTT
-----
YES
NO
YES
NO
YES
$$$TEST$$$

^^^TEST^^^
6
1
T
2
MM
5
TMMTT
6
TMMTTT
6
TTMMTT
6
TMTTMT
---
NO
NO
NO
NO
YES
YES
$$$TEST$$$


^^^TEST^^^
7
3
MMM
3
TTT
3
TTM
3
MTT
3
TMT
3
TMM
4
TTTT
---
NO
NO
NO
NO
YES
NO
NO
$$$TEST$$$

'''


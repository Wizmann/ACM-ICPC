#coding=utf-8

def kmp(s):
    n = len(s)
    kmp_next = [-1 for i in xrange(n + 1)]

    pre = -1
    suf = 0
    while pre < n and suf < n:
        if pre == -1 or s[pre] == s[suf]:
            pre += 1
            suf += 1
            kmp_next[i] = pre
        else:
            pre = kmp_next[pre]
    return kmp_next

def solve(s):
    n = len(s)
    kmp_next = kmp(s)
    it = n - kmp_next[-1]
    if n % it != 0:
        return s, 1
    return s[:it], n / it

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def lcm(a, b):
    return a * b / gcd(a, b)

T = int(raw_input())
for case_ in xrange(T):
    sa = raw_input()
    sb = raw_input()

    l = lcm(len(sa), len(sb))
    ta = l / len(sa)
    tb = l / len(sb)

    if sa * ta == sb * tb:
        print sa * ta
    else:
        print -1


'''
^^^TEST^^^
3
baba
ba
aa
aaa
aba
ab
----
baba
aaaaaa
-1
$$$TEST$$$

^^^TEST^^^
2
babaabbbaabbb
babaabbbaabbb
bbabbbab
bbabbbabbbabbbabbbab
----
babaabbbaabbb
bbabbbabbbabbbabbbabbbabbbabbbabbbabbbab
$$$TEST$$$
'''

def kmp(s):
    n = len(s)
    kmp_next = [-1 for i in xrange(n + 1)]

    pre = -1
    suf = 0
    while pre < n and suf < n:
        if pre == -1 or s[pre] == s[suf]:
            pre += 1
            suf += 1
            kmp_next[suf] = pre
        else:
            pre = kmp_next[pre]
    return kmp_next

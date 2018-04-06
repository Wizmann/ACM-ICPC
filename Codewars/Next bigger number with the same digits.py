INF = 10 ** 10

def next_bigger(n):
    s = map(int, str(n))
    n = len(s)
    
    print s
    
    for i in xrange(n - 2, -1, -1):
        if s[i] < s[i + 1]:
            mini = INF
            p = -1
            for j in xrange(i + 1, n):
                if s[j] > s[i]:
                    if s[j] < mini:
                        mini = s[j]
                        p = j
            s[i], s[p] = s[p], s[i]
            s[i + 1:] = sorted(s[i + 1:])
            return int(''.join(map(str, s)))
    return -1

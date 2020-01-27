INF = 10 ** 10
T = int(raw_input())
 
for case_ in xrange(T):
    (n, s, k) = map(int, raw_input().split())
    ks = set(map(int, raw_input().split()))
 
    mini = INF
    i = 0
    while True:
        l = s - i
        if l > 0 and l not in ks:
            mini = i
            break
        r = s + i
        if r <= n and r not in ks:
            mini = i
            break
        i += 1
    print mini

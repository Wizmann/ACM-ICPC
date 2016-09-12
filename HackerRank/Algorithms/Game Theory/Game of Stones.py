def mex(l):
    if not l:
        return 0
    ll = sorted(filter(lambda x: x >= 0, map(lambda x: x - 1, l)))
    for num in ll:
        if num not in l:
            return num
    return max(l) + 1

assert mex([0, 1, 2]) == 3
assert mex([1, 2]) == 0

N = 111
dp = [0 for i in xrange(N)]

for i in xrange(N):
    mv = [2, 3, 5]
    l = []
    for m in mv:
        if i - m >= 0:
            l.append(dp[i - m])
    dp[i] = mex(l)

T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
    
    if dp[n] == 0:
        print 'Second'
    else:
        print 'First'



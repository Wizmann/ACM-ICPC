n, x = map(int, raw_input().split())

dp = [0 for i in xrange(x + 1)]
dp[0] = 1

for i in xrange(n):
    (a, b) = map(int, raw_input().split())

    for j in xrange(30):
        if not b:
            break
        cur = 1 << j
        if cur > b:
            cur = b
        b -= cur

        for k in xrange(x, -1, -1):
            if dp[k] and k + a * cur <= x:
                dp[k + a * cur] = 1
    if dp[x]:
        break

if dp[x]:
    print 'Yes'
else:
    print 'No'


'''
^^^^TEST^^^^
2 19
2 3
5 6
--------
Yes
$$$$TEST$$$
'''

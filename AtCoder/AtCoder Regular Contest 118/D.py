P, a, b = map(int, raw_input().split())

pa = [False for i in xrange(P)]
va = [0 for i in xrange(P)]
loop_a = 0

pb = [False for i in xrange(P)]
vb = [0 for i in xrange(P)]
loop_b = 0

for i in xrange(0, P + 1):
    u = pow(a, i, P)
    if pa[u] == True:
        loop_a = i
        break
    pa[u] = True
    va[i] = u

for i in xrange(1, P + 1):
    u = pow(b, i, P)
    if pa[u] == True:
        loop_b = i
        break
    pb[u] = True
    vb[i] = u

# print va
# print vb

if P - 1 != loop_a * loop_b:
    print 'No'
else:
    if (P - 1) % loop_a == 0:
        loop_b = (P - 1) / loop_a
    elif (P - 1) % loop_b == 0:
        loop_a = (P - 1) / loop_b

    # print loop_a, loop_b

    dp = [[-1 for j in xrange(loop_b)] for i in xrange(loop_a)]

    dp[0][0] = 1

    for i in xrange(loop_a):
        for j in xrange(loop_b):
            dp[i][j] = pow(a, i, P) * pow(b, j, P) % P

    res = []
    if loop_a % 2 == 0:
        for i in xrange(loop_a):
            sub = []
            for j in xrange(loop_b):
                sub.append(dp[i][j])
            if i % 2:
                sub = sub[::-1]
            res += sub
    else:
        for i in xrange(loop_b):
            res.append(dp[0][i])
        for j in xrange(loop_b - 1, -1, -1):
            sub = []
            for i in xrange(1, loop_a):
                sub.append(dp[i][j])
            if (loop_b - j - 1) % 2:
                sub = sub[::-1]
            res += sub

    res.append(1)
    print 'Yes'
    print ' '.join(map(str, res))

'''
^^^TEST^^^
13 4 5
-----
Yes
1 5 11 3 12 9 7 4 6 8 2 10 1
$$$TEST$$$

^^^TEST^^^
13 1 2
-----
Yes
1 2 4 8 3 6 12 11 9 5 10 7 1
$$$TEST$$$

^^^TEST^^^
13 9 3
----
No
$$$TEST$$$

^^^TEST^^^
13 1 1
----
No
$$$TEST$$$
'''

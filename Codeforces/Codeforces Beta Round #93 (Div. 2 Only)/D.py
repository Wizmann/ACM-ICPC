import heapq

def z_function(s):
    n = len(s)
    z = [0] * n
    l, r = 0, 0
    for i in range(1, n):
        if i <= r and z[i - l] < r - i + 1:
            z[i] = z[i - l]
        else:
            z[i] = max(0, r - i + 1)
            while i + z[i] < n and s[z[i]] == s[i + z[i]]:
                z[i] += 1
        if i + z[i] - 1 > r:
            l = i
            r = i + z[i] - 1
    return z


s = raw_input()
z = z_function(s)

n = len(s)

pq = []
res = 0

for i in xrange(n):
    if i + z[i] == n:
        if pq and -pq[0] >= z[i]:
            res = z[i]
            break
    if z[i]:
        heapq.heappush(pq, -z[i])

if res:
    print s[:res]
else:
    print 'Just a legend'

'''
^^^^TEST^^^
fixprefixsuffix
------
fix
$$$$TEST$$$$

^^^^TEST^^^
abcdabc
------
Just a legend
$$$$TEST$$$$

^^^^TEST^^^
qwertyqwertyqwerty
------
qwerty
$$$$TEST$$$$

^^^^TEST^^^
papapapap
------
papap
$$$$TEST$$$$
'''



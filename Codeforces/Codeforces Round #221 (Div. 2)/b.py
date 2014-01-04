#Result: Dec 24, 2013 6:12:53 PM    Wizmann  B - I.O.U.  Python 2   Accepted     46 ms   0 KB
(n, m) = map(int, raw_input().split())
inv = [0 for i in xrange(n + 5)]
outv = [0 for i in xrange(n + 5)]

for i in xrange(m):
    (a, b, c) = map(int, raw_input().split())
    outv[a] += c
    inv[b] += c

res = 0
for i in xrange(n + 5):
    res += abs(inv[i] - outv[i])

while res % 2 != 0:
    #Trick，如果res % 2 != 0的话，我的算法就是完全错误的
    #此时返回TLE而不是WA
    pass

print res / 2


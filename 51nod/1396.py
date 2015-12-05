s = raw_input()
n = len(s)

zeros, ones = [0] * n, [0] * n

cnt = 0
for i in xrange(n):
    if s[i] == '0':
        cnt += 1
    zeros[i] = cnt

cnt = 0
for i in xrange(n - 1, -1, -1):
    if s[i] == '1':
        cnt += 1
    ones[i] = cnt
    
for i in xrange(n + 1):
    l = 0 if i - 1 < 0 else zeros[i - 1]
    r = 0 if i >= n else ones[i]
    if l == r:
        print i
        break
else:
    print -1
